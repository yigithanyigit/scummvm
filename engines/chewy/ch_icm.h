/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef CHEWY_CHICM_H
#define CHEWY_CHICM_H

void set_person();

void draw_ice_win();

void get_room_nr();

void room_info();

void plot_auto_mov(int16 mode);

void go_auto_mov();

void get_rect(char *spr1, int16 x1, int16 y1, char *spr2, int16 x2, int16 y2);
void plot_maus();
void plot_rect();

void get_auto_mov();
void start_detail();
void play_last_ani(int16 nr);

void set_z_ebene();
void get_phase(ObjMov *om, MovInfo *mi);

void save_iib(char *fname);

int16 ja_nein();

void load_org();

void calc_mouse_scroll(int16 scrx, int16 scry);
void get_scroll_val();

void get_zoom_value();

IibDateiHeader iib_datei_header;

#endif
