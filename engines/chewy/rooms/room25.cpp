/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "chewy/defines.h"
#include "chewy/events.h"
#include "chewy/global.h"
#include "chewy/ani_dat.h"
#include "chewy/room.h"
#include "chewy/rooms/room23.h"
#include "chewy/rooms/room25.h"

namespace Chewy {
namespace Rooms {

#undef SURIMY_OBJ
#define SURIMY_OBJ 0

static const int16 SURIMY_PHASEN[4][2] = {
	{ 56, 63 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 }
};

static const MovLine SURIMY_MPKT[2] = {
	{ { 100, 150, 150 }, 0, 6 },
	{ { -20, 150, 150 }, 0, 6 }
};

void Room25::entry() {
	if (!_G(spieler).R29Schlauch2) {
		det->hide_static_spr(0);
		det->hide_static_spr(1);
	}
	if (!_G(spieler).R25FirstEntry) {
		hide_cur();
		if (obj->check_inventar(TRANSLATOR_INV)) {
			obj->calc_rsi_flip_flop(SIB_TRANSLATOR_23);
			atds->set_ats_str(113, 0, ATS_DATEI);

			obj->del_inventar(TRANSLATOR_INV, &room_blk);
			_G(spieler).inv_cur = false;
			menu_item = CUR_WALK;
			_G(spieler).AkInvent = -1;
			cursor_wahl(menu_item);
			del_invent_slot(TRANSLATOR_INV);
		}
		_G(spieler).R25FirstEntry = true;
		_G(spieler).PersonHide[P_CHEWY] = true;
		flic_cut(FCUT_029, FLC_MODE);
		fx_blend = BLEND_NONE;
		set_person_pos(219, 141, P_CHEWY, P_RIGHT);
		_G(spieler).PersonHide[P_CHEWY] = false;
		start_spz(CH_TALK11, 255, ANI_VOR, P_CHEWY);
		start_aad_wait(64, -1);
		show_cur();
	} else if (_G(spieler).R25GleiterExit) {
		set_person_pos(127, 122, P_CHEWY, P_LEFT);
		if (_G(spieler).R25SurimyGo < 1) {
			++_G(spieler).R25SurimyGo;
		} else {
			_G(spieler).R25GleiterExit = false;
			xit_gleiter();
		}
	}
}

int16 Room25::gleiter_loesch() {
	int16 action_flag = false;
	if (!_G(spieler).R25GleiteLoesch && _G(spieler).R29Schlauch2) {
		if (!_G(spieler).inv_cur) {
			action_flag = true;
			_G(spieler).R25GleiteLoesch = true;
			auto_move(2, P_CHEWY);
			flic_cut(FCUT_030, FLC_MODE);
			obj->calc_rsi_flip_flop(SIB_SCHLAUCH_R25);
			atds->set_ats_str(219, 1, ATS_DATEI);
			atds->set_ats_str(187, 1, ATS_DATEI);
		}
	} else if (_G(spieler).R25GleiteLoesch) {
		if (is_cur_inventar(MILCH_LEER_INV)) {
			action_flag = true;
			auto_move(2, P_CHEWY);
			start_spz_wait(CH_LGET_U, 1, ANI_VOR, P_CHEWY);
			del_inventar(_G(spieler).AkInvent);
			obj->add_inventar(MILCH_WAS_INV, &room_blk);
			inventory_2_cur(MILCH_WAS_INV);
			start_aad_wait(253, -1);
		}
	}
	return action_flag;
}

int16 Room25::use_gleiter() {
	int16 action_flag = false;
	if (!_G(spieler).inv_cur && _G(spieler).R25GleiteLoesch) {
		action_flag = true;
		auto_move(3, P_CHEWY);
		_G(spieler).R23GleiterExit = 25;
		Room23::cockpit();
	}
	return action_flag;
}

void Room25::xit_gleiter() {
	if (!_G(spieler).R25SurimyLauf) {
		_G(spieler).R25SurimyLauf = true;
		det->load_taf_seq(56, 8, 0);
		_G(auto_obj) = 1;
		mov_phasen[SURIMY_OBJ].AtsText = 0;
		mov_phasen[SURIMY_OBJ].Lines = 2;
		mov_phasen[SURIMY_OBJ].Repeat = 1;
		mov_phasen[SURIMY_OBJ].ZoomFak = 0;
		auto_mov_obj[SURIMY_OBJ].Id = AUTO_OBJ0;
		auto_mov_vector[SURIMY_OBJ].Delay = _G(spieler).DelaySpeed + 2;
		auto_mov_obj[SURIMY_OBJ].Mode = true;
		init_auto_obj(SURIMY_OBJ, &SURIMY_PHASEN[0][0], mov_phasen[SURIMY_OBJ].Lines,
			(const MovLine *)SURIMY_MPKT);
		fx_blend = BLEND1;
		set_up_screen(DO_SETUP);
		start_spz(CH_TALK12, 255, ANI_VOR, P_CHEWY);
		start_aad_wait(65, -1);
		fx_blend = BLEND_NONE;
		wait_auto_obj(SURIMY_OBJ);
		_G(auto_obj) = 0;
	}
}

} // namespace Rooms
} // namespace Chewy
