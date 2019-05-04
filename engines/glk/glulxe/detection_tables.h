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

#include "engines/game.h"
#include "common/gui_options.h"
#include "common/language.h"

namespace Glk {
namespace Glulxe {

/**
 * Game description
 */
struct GlulxeGameDescription {
	const char *const _gameId;
	const char *const _extra;
	const char *const _md5;
	size_t _filesize;
	Common::Language _language;
};

const PlainGameDescriptor GLULXE_GAME_LIST[] = {
	{ "glulx", "Glulx Game" },

	// English games
	{ "aafn", "An Apple From Nowhere" },
	{ "acg", "Adventurer's Consumer Guide" },
	{ "adventglulx", "Adventure" },
	{ "adventura", "Adventura" },
	{ "airport", "The Airport" },
	{ "alabaster", "Alabaster" },
	{ "aliasthemagpie", "Alias 'The Magpie'" },
	{ "alongdrink", "A Long Drink" },
	{ "anatidaephobia", "A N A T I D A E P H O B I A" },
	{ "anchorheaddemo", "Anchorhead: Special Edition Demo" },
	{ "andromeda1983", "Andromeda 1983" },
	{ "andromedaapocalypseext", "Andromeda Apocalypse (Extended Edition)" },
	{ "andromedaascending", "Andromeda Ascending" },
	{ "andromedaawakening", "Andromeda Awakening - The Final Cut"},
	{ "ariadneinaeaea", "Ariadne in Aeaea" },
	{ "aroilingoriginal", "A Roiling Original: Squeeal! A Sequel!" },
	{ "artoffugue", "Art of Fugue" },
	{ "atc", "ATC, an interactive aviation" },
	{ "aurora", "Aurora" },
	{ "balancesglulx", "Balances" },
	{ "baretegi", "Baretegi" },
	{ "barroombrawl", "Barroom Brawl: Punch for your life" },
	{ "beasttorrackmoor", "The Beast of Torrack Moor" },
	{ "beautyaustere", "A Beauty Cold and Austere" },
	{ "becauseyouremine", "Because You're Mine" },
	{ "beingthere", "Being There" },
	{ "beyondglulx", "Beyond" },
	{ "bluelacuna", "Blue Lacuna" },
	{ "bonehead", "Bonehead, a Regrettable and Mostly True Tale" },
	{ "brainguzzlers", "Brain Guzzlers from Beyond!" },
	{ "briar", "Briar, a Grimmly Perverted Fairy Tale" },
	{ "btyt", "Bigger Than You Think" },
	{ "bullhockey", "Bullhockey!" },
	{ "bureaucrocyglulx", "Bureaucrocy, a boring tale about paperwork" },
	{ "buygold", "Buy Gold" },
	{ "calm", "Calm, a Game of Postapocalyptic Relaxation" },
	{ "candlewindless", "Candle flames in windless air" },
	{ "canyouescape", "Can You Escape" },
	{ "piedaterreblunders", "Captain Piedaterre's Blunders" },
	{ "castronegroblues", "Castronegro Blues" },
	{ "caveglulx", "Cave" },
	{ "cheesedoffglulx", "Cheesed Off! A very cheesey adventure" },
	{ "chlorophyll", "Chlorophyll" },
	{ "chnlsurf", "Channel Surfing" },
	{ "codetopia", "Codetopia - A Code Adventure" },
	{ "colderlight", "The Colder Light: A Winter's Tale" },
	{ "colorthetruth", "Color the Truth" },
	{ "comp01tr", "Comp01ter Game: N0n C0mp0s Ment1s" },
	{ "cos", "City of Secrets" },
	{ "counterfeitmonkey", "Counterfeit Monkey" },
	{ "countingcrabs", "Counting Crabs: How many crabs can you count?" },
	{ "crackcoldone", "Crack open a cold one with the Boiz" },
	{ "cragne", "Cragne Manor" },
	{ "damesdeadites", "Dames and Deadites" },
	{ "dansenocturne", "Danse Nocturne" },
	{ "darkcarnival", "Dark Carnival" },
	{ "darknessglulx", "Darkness" },
	{ "deadcities", "Dead Cities" },
	{ "deathoffthecuff", "Death Off the Cuff" },
	{ "delphinashouse", "Delphina's House" },
	{ "diaperquest", "Diaper Quest" },
	{ "discovertheworld", "Discover The World" },
	{ "doctorm", "The Life (and Deaths) of Doctor M" },
	{ "douchebag", "Douchebag, an Existential Adventure" },
	{ "downtheserpent", "Down, the Serpent and the Sun: an Anatomy" },
	{ "donotmeddle", "Do Not Meddle" },
	{ "dracula1glulx", "Dracula: Part 1, The First Night" },
	{ "dracula2glulx", "Dracula: Part 2, The Arrival" },
	{ "dragondemons", "Dragon Demons: A World Traveling RPG" },
	{ "dragonglulx", "Dragon Adventure" },
	{ "drolltolltroll", "Droll Toll Troll" },
	{ "dudewheresmyscapula", "Dude, Where's My Scapula" },
	{ "dungeonspuzzle", "Dungeon's Puzzle" },
	{ "dungeontext1", "Dungeon Text I - Escape From Darkness" },
	{ "eas2", "Another Earth, Another Sky. Earth And Sky: Episode 2" },
	{ "endlesssands", "Endless Sands" },
	{ "endling", "The Endling Archive" },
	{ "enterpriseincidents", "The Enterprise Incidents: A Middle School Fantasy" },
	{ "everybodydies", "Everybody Dies, an Interactive Fantasy" },
	{ "fair", "Fair, an extra-curricular activity" },
	{ "farmquest", "Farm Quest" },
	{ "ferrousring", "Ferrous Ring" },
	{ "finalproject", "Final Project" },
	{ "flexiblesurvival", "Flexible Survival" },
	{ "followingastar", "The Bible Retold: Following A Star" },
	{ "further", "Further, a color-coded existential tangle" },
	{ "genesisquest", "Genesis Quest, an interlude through stories" },
	{ "ghosteringtonnight", "Ghosterington Night" },
	{ "glkchess", "Glk Chess" },
	{ "glkebook", "GlkeBook" },
	{ "greenmountains", "The Green Mountains" },
	{ "groovebillygoat", "Groove Billygoat" },
	{ "hardpuzzle1", "Hard Puzzle" },
	{ "hardpuzzle2", "Hard Puzzle 2: The Cow" },
	{ "hardpuzzle3", "Hard Puzzle 3: Origins" },
	{ "haroldnight2003", "Harold Night 2003" },
	{ "killerheadache", "A Killer Headache" },
	{ "herecomestreble", "Here Comes Treble" },
	{ "hobbitglulx", "The HObbit - The True Story" },
	{ "hungerdaemon", "Hunger Daemon" },
	{ "illum", "Illuminismo Iniziato, an Interactive Illumination" },
	{ "Illwind", "Ill Wind, Yet Another Interactive Enigma" },
	{ "ingoodcompany", "In Good Company" },
	{ "kerkerkruip", "Kerkerkruip" },
	{ "klaustrophobia", "Klaustrophobia" },
	{ "koa", "Kingdom of Amphibia" },
	{ "lastresort", "Last Resort, a sweltering afternoon in the Deep South" },
	{ "limeergot", "Lime Ergot" },
	{ "lmstvgglulx", "LMS The Video Game" },
	{ "lockkey", "Lock and Key" },
	{ "lockdown", "Lockdown: a story of insanity, denial and death" },
	{ "makechangeglulx", "Maybe make some change" },
	{ "mollybutterthieves", "Molly and the Butter Thieves" },
	{ "moments1", "Moments out of Time: Renegade" },
	{ "moments2", "Moments out of Time 2: Adventure Type" },
	{ "moonbaseindigo", "Moonbase Indigo" },
	{ "mugglestudies", "Muggle Studies" },
	{ "mgaeb", "My Girlfriend's An Evil Bitch" },
	{ "mystery", "Mystery!" },
	{ "narco", "Narcolepsy" },
	{ "necronskeep", "Necron's Keep" },
	{ "newcat", "New Cat" },
	{ "nightfall", "Nightfall" },
	{ "nightmare", "Nightmare" },
	{ "nssri", "No Sign Should Remain Inert" },
	{ "oldfogey", "Old Fogey" },
	{ "oliviasorphanorium", "Olivia's Orphanorium" },
	{ "oppositelyopal", "Oppositely Opal" },
	{ "ottumwaglulx", "PDFA Ottumwa" },
	{ "owlconsults", "The Owl Consults" },
	{ "oxygen", "Oxygen" },
	{ "patanoir", "PataNoir" },
	{ "phoenixfire", "Phoenix-Fire" },
	{ "photopiaglulx", "Photopia" },
	{ "pinched", "Pinched" },
	{ "pizzadelivery", "Pizza Delivery" },
	{ "playinggames", "Playing Games" },
	{ "portfoliopiece", "Portfolio Piece" },
	{ "psychomanteum", "Psychomanteum" },
	{ "pythoglulx", "Pytho's Mask" },
	{ "rar", "Reference and Representation: An Approach to First-Order Semantics" },
	{ "reorsbushcaveglulx", "Reor's Bush-Cave" },
	{ "risorgglulx", "Risorgimento Represso" },
	{ "robinandorchid", "Robin & Orchid" },
	{ "rosewood", "he House at the End of Rosewood Street" },
	{ "rover", "Rover's Day Out" },
	{ "safe", "Safe" },
	{ "sagebrushcactus", "'Mid the sagebrush and the cactus" },
	{ "samfortunepi", "Sam Fortune - Private Investigator" },
	{ "scrollthief", "Scroll Thief, an Interactive Heist" },
	{ "section1awakened", "Section 1 - Awakened" },
	{ "sensory", "Sensory Jam" },
	{ "sequitur", "Sequitur" },
	{ "shapes", "Shapes: an Interactive Surrealism" },
	{ "sheephere", "Sheep Here" },
	{ "shufflingaround", "Shuffling Around" },
	{ "signalerror", "Signal Error: Tongue-in-cheek glitch correction" },
	{ "sittm", "Stick It To The Man" },
	{ "six", "Six" },
	{ "smittenkittens", "Smitten Kittens" },
	{ "skmmc", "Someone Keeps Moving My Chair" },
	{ "spaceship", "Spaceship!" },
	{ "spellbound", "Spellbound" },
	{ "spirI7wrak", "SpirI7wrak" },
	{ "starlight", "Starlight" },
	{ "subrosa", "Sub Rosa: The Seven Deceits of Confessor Destine" },
	{ "superluminalvagranttwin", "Superluminal Vagrant Twin" },
	{ "tacoFiction", "Taco Fiction" },
	{ "terminatorrobotrescue", "Terminator, a Robot Rescue" },
	{ "tcom", "The Colour of Magic" },
	{ "duelspannedages", "The Duel that Spanned the Ages" },
	{ "equivocalingredient", "The Equivocal Ingredient" },
	{ "houseofmystery",  "The House of Mystery" },
	{ "kingshredspatches", "The King of Shreds and Patches" },
	{ "lostislandsofalabaz", "The Lost Islands of Alabaz" },
	{ "theabbey", "The Abbey, a medieval murder mystery" },
	{ "thehours", "The Hours" },
	{ "thehouseoffear", "The House of Fear, or, Loplop Introduces the World" },
	{ "thelibrary", "The Library" },
	{ "themuseum", "The Museum" },
	{ "thephoenixmove", "The Phoenix Move" },
	{ "rocketmanfromsea", "The Rocket Man from the Sea" },
	{ "thesimpletale", "The Simple Tale" },
	{ "theskycrane", "The Sky Crane" },
	{ "thespywhoatelunch", "The Spy Who Ate Lunch" },
	{ "thethiefofwovenwoods", "The Thief of Woven Woods" },
	{ "thetinyhouse", "THe Tiny House" },
	{ "theabsenceoflaw", "The Absence of Law" },
	{ "ascentgothictower", "The Ascent of the Gothic Tower" },
	{ "thebox", "The Box" },
	{ "thefourthriddle", "The Fourth Riddle" },
	{ "theinformal7abbreviated", "The Inform(al)7 Abbreviated Self Tutorial" },
	{ "theislandofdoctorwooby", "The Island of Doctor Wooby" },
	{ "thelaughinggnome", "The Laughing Gnome" },
	{ "thelostkingdomofcodetopia", "The Lost Kingdom of Codetopia" },
	{ "themaryjaneoftomorrow", "The Mary Jane of Tomorrow" },
	{ "theoutcasts", "The Outcasts" },
	{ "therealmofaoria", "The Realm of A'oria" },
	{ "thestorm", "The Storm, a self-portrait" },
	{ "thetraintoabaddon", "The Train To Abaddon" },
	{ "thiefpokemon", "Thief, a Pokemon Text Adventure" },
	{ "tohellinahamper", "To Hell in a Hamper" },
	{ "transparent", "Transparent, an interactive exploration" },
	{ "trialofthetnuop", "Trial of the Inuop" },
	{ "trollslayer", "Trollslayer" },
	{ "tryagain", "Try Again " },
	{ "uglyoafs", "Ugly Oafs. Save Green Terra! Repel the Wrath Pulse!" },
	{ "uie", "Under, In Erebus" },
	{ "unscientificfiction", "Unscientific Fiction" },
	{ "valleyofsteel", "Valley of Steel" },
	{ "wand", "The Wand" },
	{ "winterstormdraco", "Winter Storm Draco" },
	{ "wishertheurgist", "Wisher, Theurgist, Fatalist" },
	{ "wof", "Works of Fiction" },
	{ "wordoftheday", "Word of the Day" },
	{ "wordsofpower", "Words of Power" },
	{ "zorkglulx", "Zork: A Computerized Fantasy Simulation Game" },

	// Apollo 18+20 IF Tribute Album
	{ "apollo3glulx", "She's Actual Size" },
	{ "apollo10glulx", "Narrow Your Eyes" },
	{ "apollo12glulx", "Which Describes How You're Feeling" },
	{ "apollo15glulx", "Turn Around" },
	{ "apollo19glulx", "Fingertips - I Hear the Wind Blow" },
	{ "apollo33glulx", "Fingertips - Mysterious Whispers" },

	// French games
	{ "ekphrasis", "Ekphrasis, les Aventures de Gilbert Fontenelle" },
	{ "lieuxcommunsglulx", "Lieux communs" },
	{ "sarvegneglulx", "Sarvegne, une visite qui conduit loin" },
	{ "scarabeekatana", "Le Scarabee et le Katana" },
	{ "templefeu", "Le Temple de Feu" },

	// German games
	{ "dergarten", "Der onirische Garten" },
	{ "deronirischegarten", "Der unsagliche und vermeidbare Tod des Matthias Claudius" },
	{ "matthiasclaudius", "Der Garten: Der Aufenthalt in einem traumhaften Garten" },
	{ "morgenwirdklausur", "Morgen wird Klausur geschrieben" },
	{ "patanoirde", "PataNoir - Ein unvergleichlicher Kriminalfall" },

	// Italian games
	{ "pietradellaluna", "La Pietra della Luna" },
	{ "mancasolo", "Manca solo un verso a quella poesia" },
	{ "schizo", "Schizo - Escape to the Void" },
	{ "snuff", "Snuff Movie" },
	{ "villamorganaglulx", "Villa Morgana" },

	// Spanish games
	{ "alienlaaventura", "ALIEN: La Aventura" },
	{ "conrumbo", "Con Rumbo" },
	{ "elultimohogarglulx", "Misterio en el �ltimo Hogar" },
	{ "hhorcusglulx", "Homo Homini Orcus" },
	{ "kerulenglulx", "Ke rulen los petas" },
	{ "lanochedelensayo", "La Noche del Ensayo" },
	{ "legado", "El Legado" },
	{ "regente", "El Anillo Regente" },
	{ "rur", "Las Aventuras de Rudolphine Rur" },

	// Swedish games
	{ "drakmagiglulx", "Drakmagi (Dragon Magic)" },
	{ "vanyarglulx", "Vanyar" },

	{ nullptr, nullptr }
};

#define ENTRY0(ID, MD5, FILESIZE) { ID, nullptr, MD5, FILESIZE, Common::EN_ANY }
#define ENTRY1(ID, EXTRA, MD5, FILESIZE) { ID, EXTRA, MD5, FILESIZE, Common::EN_ANY }
#define ENTRYL0(ID, MD5, FILESIZE, LANG) { ID, nullptr, MD5, FILESIZE, LANG }
#define ENTRYL1(ID, EXTRA, MD5, FILESIZE, LANG) { ID, EXTRA, MD5, FILESIZE, LANG }
#define TABLE_END_MARKER { nullptr, nullptr, nullptr, 0, Common::EN_ANY }

const GlulxeGameDescription GLULXE_GAMES[] = {
	// English games
	ENTRY0("aafn", "98c22f842ffadfb08a8e2a93d32c7495", 163328),
	ENTRY1("acg", "070501", "1a3eb782d28dd8ae8da40f21adb174f0", 817408),
	ENTRY1("adventglulx", "961209", "e1939485dc2d4aab637144fc842b479d", 195406),
	ENTRY1("adventglulx", "961209", "cf232df2a3364a6f0821a8ef631c81a1", 167424),
	ENTRY1("adventura", "171031", "4ca16a77854814124e1ab8df7270ed20", 659912),
	ENTRY1("airport", "080204", "d3db494abc309a42b4dccfa53243a783", 234728),
	ENTRY1("alabaster", "090609", "7f664b6eef28485a2f85a1831b041246", 3132122),
	ENTRY1("aliasthemagpie", "190206", "a4281a03b797582ea53aa203b1eb7236", 1875956),
	ENTRY1("alongdrink", "150214", "8120604cd0cb566897fdb0f2786f4b43", 2164954),
	ENTRY1("anatidaephobia", "170121", "a651c03db50e624fc8da5679ac731b53", 786902),
	ENTRY1("anchorheaddemo", "070202", "f2e60c4c3aad4c6a2b18d4d20040ed76", 635974),
	ENTRY0("andromeda1983", "dcb44d52f383a4ae813145630202d49c", 9580734),
	ENTRY0("andromedaapocalypseext", "c740f7c85f5d673e0fb6b216e0433332", 7464444),
	ENTRY0("andromedaascending", "5947436a0109a634506691ee744d6e3e", 1752292),
	ENTRY1("andromedaawakening", "120121", "64b2e5268c154130dc0d46b40c4e3e94", 884850),
	ENTRY1("ariadneinaeaea", "161129", "f796d793ea7b26e21abf6478ecb841a8", 1219646),
	ENTRY1("aroilingoriginal", "150327", "48719b01e0b805df27fcf1e021c6780f", 3731214),
	ENTRY1("artoffugue", "100911", "2be7f91abade14d81b85843d82d52e86", 21605450),
	ENTRY1("artoffugue", "100911 No Music", "b570048a98acb680b8305043f1f1c866", 1596664),
	ENTRY0("atc", "312ef9bf8d06145948994ad596c57ce3", 65536),
	ENTRY1("aurora", "110219", "5561b20f74d67b0e71c2b73c2ca85943", 2198110),
	ENTRY1("beautyaustere", "180112", "7efa8da4a65c8e70f6783f30750f7a00", 2127234),
	ENTRY1("beautyaustere", "180928", "41a6d2b620c211118e2b9586fd354ea7", 2127234),
	ENTRY1("balancesglulx", "961216", "84e0bc6295bc979754d0aa40982d1a12", 383542),
	ENTRY1("baretegi", "160131", "8f1ea267fca902d07c41cb5fae8a6efb", 651420),
	ENTRY1("barroombrawl", "160226", "a6b2641c76c1a28e5ff8f5188a06c63e", 637692),
	ENTRY1("beasttorrackmoor", "071014", "80d093ceb324b7288b6c5715f8391d3d", 579578),
	ENTRY1("becauseyouremine", "161019", "643df12ae55ed54c9c1172753fc71d52", 648134),
	ENTRY0("beingthere", "6a7f51d6c09acca156e3ceadce7edcb9", 6005766),
	ENTRY0("beyondglulx", "64a351bc6757a58080b801a14d878fc2", 1303364),
	ENTRY1("bluelacuna", "090304", "86c24b7fa879780038056d5e9a084a28", 5649260),
	ENTRY1("bonehead", "120229", "34563c2af093239b5a908a64031eedac", 1804252),
	ENTRY1("brainguzzlers", "160123", "23d22c7e8d7dff3660c436ef4951f4ae", 3210594),
	ENTRY1("briar", "130707", "fb40823ab510ca052c8736163332ea6d", 766272),
	ENTRY1("btyt", "130101", "97c6c3622d0d5a2f7a5e4f9ca521c13d", 412214),
	ENTRY1("bullhockey", "181125", "8919f32151fdc862688fb3c27aa7c46d", 2036232),
	ENTRY1("bullhockey", "181218", "8414393ff71519dc842cfe758ac2b0ad", 2066952),
	ENTRY1("bullhockey", "181220", "a2ad2f228e37ea52062e4f4f110232d3", 2065672),
	ENTRY1("bullhockey", "190103", "6cec5f7e1bfba0cbfa76bad81c197eba", 2065672),
	ENTRY1("bullhockey", "190106", "877fd221c0f6e7f7393597a8c6a4e3ca", 2065672),
	ENTRY1("bureaucrocyglulx", "140401", "530a9efefff27ce37d75e5dc8de8ad5d", 565522),
	ENTRY1("buygold", "160302", "7db70c24b2533800187a1884ca9eacf1", 897480),
	ENTRY1("calm", "111201", "dba39ece18ebfbde9ebc93ccc5216fd8", 2012688),
	ENTRY1("candlewindless", "170828", "8decde9d474d5888d46684b8958c3a3d", 2281490),
	ENTRY1("canyouescape", "131027", "330ec51e1f138a5f28df687c749ac959", 339406),
	ENTRY1("piedaterreblunders", "171216", "6195647baed23df20a1e16e02d046505", 1115466),
	ENTRY1("castronegroblues", "130314", "fa6a51335c716de20510bd418081295b", 695186),
	ENTRY1("caveglulx", "040606", "67d3036084bb769ae925a8b6f3be84ed", 279960),
	ENTRY1("cheesedoffglulx", "160315", "27a5288bce1b9aed55c150cba9f2e930", 666448),
	ENTRY1("chlorophyll", "150212", "447eae9f3c961baec28cbef9432839e7", 1089226),
	ENTRY1("chnlsurf", "081122", "131aac0607a2ed5f3ae8c333bc981cd6", 409856),
	ENTRY1("codetopia", "171103", "40f486f5a68fee9d99623167cf750874", 682480),
	ENTRY1("colderlight", "120312", "eed41f2779bdf940f84b4e0a33036e69", 1192960),
	ENTRY0("colorthetruth", "b9ea873d69fd82d1e0535d55b4b84cac", 1372266),
	ENTRY0("comp01tr", "1d51522ee3057a3f7206fa83c151a6de", 149760),
	ENTRY1("cos", "030624", "21bbf38c4e358ff2fd34e3d7424c8d36", 8462908),
	ENTRY1("counterfeitmonkey", "160520", "24b94c1d870740880629983fc181d7b8", 14806568),
	ENTRY1("counterfeitmonkey", "171224", "340232662aa8e9f4d45726e8ca7f9f5a", 12580166),
	ENTRY1("counterfeitmonkey", "181204", "c3e41db7aa8642f40b157c51fa91a26b", 12348938),
	ENTRY1("countingcrabs", "090728", "ffc19674d99b4d6f530bb00287c83c7e", 1508676),
	ENTRY1("crackcoldone", "170706", "c2d5bf64a0aadaead7640b5750826d55", 627136),
	ENTRY1("crackcoldone", "170711", "d64bd51d8fe05dc190ac3589e11b6ea6", 627136),
	ENTRY1("cragne", "181208", "082f518c0120d2323ce340bef8a2d5a9", 8869096),
	ENTRY1("damesdeadites", "150116", "c34b65232be2c25e558c31349e62b716", 812810),
	ENTRY0("dansenocturne", "9a60eadb746e34c7364cbe423b712e0c", 810990),
	ENTRY1("darkcarnival", "130924", "e5102c61fcb3b192c6455f214f6ca01d", 1733174),
	ENTRY1("darknessglulx", "130704", "5fd073140b9c9e0a312995e60e6761b9", 608574),
	ENTRY1("deadcities", "081214", "0d276d62017b6b1b9e07b79e3fd98b5f", 1195136),
	ENTRY1("deathoffthecuff", "130930", "8e48819a77855adf1a1879b2fb2e03ab", 1211826),
	ENTRY1("delphinashouse", "150214", "5c6e7d0f23ccc3fb17d64bcfdc14ae5e", 2199754),
	ENTRY1("diaperquest", "171224", "31d355119d0aa4c719cd8093457857b3", 417101284),
	ENTRY1("discovertheworld", "150731", "77b1b18260082d25f4de51318e885eaa", 17127846),
	ENTRY1("doctorm", "120219", "7fb0073619cb071dd5d1be97285e6454", 1293208),
	ENTRY1("douchebag", "150117", "20372d8a1cc2c6c8181f4ea7d6ec2a6c", 750454),
	ENTRY1("downtheserpent", "150214", "276a492ca99e76827265a70f84bcddd7", 1456140),
	ENTRY0("donotmeddle", "7f2864618567e6d8f587ea5dc9afe879", 800588),
	ENTRY1("dracula1glulx", "071227", "5cb76c66a0087ac70d61e21d99cdf26a", 448324),
	ENTRY1("dracula2glulx", "080819", "8b78b92771fc0f368ebc7fd0ff8e79bb", 696250),
	ENTRY1("dragondemons", "000001", "ce5c6c3e9eb5c45d83edcdba263729e9", 982528),
	ENTRY1("dragonglulx", "040211", "8daf42fd31e76a075fd2a831e6be23ac", 1625986),
	ENTRY1("drolltolltroll", "131021", "518955b338fca036fa9611c86c30f9ae", 435544),
	ENTRY1("dudewheresmyscapula", "160323", "95911f3a23498a24912f5cf64ddfb88d", 642518),
	ENTRY1("dungeonspuzzle", "180428", "6f9413eb4901da34adbdd79753094c2a", 662208),
	ENTRY1("dungeontext1", "130317", "1c69e410ff3fa7c7dcf83875a7f3a963", 746466),
	ENTRY1("eas2", "030112", "fc2b4a123489076679597a57d04c5acc", 845600),
	ENTRY1("endlesssands", "150215", "2105d775eb759af04ab788e046d965e0", 982748),
	ENTRY1("endlesssands", "150712", "55b31591423b011bb99be2724a6bdbe9", 1005788),
	ENTRY1("endling", "090217", "52500f2301277154258d2a846d45aedb", 148908),
	ENTRY1("enterpriseincidents", "020428", "ab2d1e4dd1ca079b502bc92b3ac4a1ac", 1067372),
	ENTRY1("everybodydies", "081116", "2ec12958967c78e39c5ef3b9ef8fd584", 4091308),
	ENTRY1("fair", "161116", "eca63537d9198a10dd6a84bf51b097b6", 1190090),
	ENTRY1("farmquest", "111028", "e49e02b73047fb16427c8882035a4be6", 415940),
	ENTRY1("ferrousring", "1007276", "af11f50b1ef9ba444bd176de4ee22002", 432128),
	ENTRY1("finalproject", "140517", "9ace3f9fa908a3b96a6153afa0e30720", 738248),
	ENTRY1("flexiblesurvival", "110307", "0d225782edd27fffb7ab0e423e9bad4d", 860108),
	ENTRY1("followingastar", "034107", "fec0b3c288daa456c3feff5e10bced8a", 1172892),
	ENTRY1("further", "150117", "227bf3da188ae42e43b8b88b66561252", 682770),
	ENTRY1("genesisquest", "140319", "c51f6d78e73aa0d846a2e38d4c187cfc", 1647616),
	ENTRY1("ghosteringtonnight", "150815", "29ee591bd93084b5a450f2324d47de3b", 1940030),
	ENTRY0("glkchess", "43a14ea7a35d7944504d3017f33fd40b", 252340),
	ENTRY0("glkebook", "1dc4d02840ee7cbf61dc359bc6a69c22", 61162),
	ENTRY1("greenmountains", "110116", "4049179c3a28703705de72be734e05bc", 337868),
	ENTRY1("groovebillygoat", "140511", "bfe3b34019ab6d2df0b9a5b793414170", 853042),
	ENTRY1("hardpuzzle1", "151117", "ee0a36c15599629bfc4fef9d3d83f70f", 601068),
	ENTRY1("hardpuzzle2", "151209", "db2880a4bf6539b30b922c83d1f35877", 626752),
	ENTRY1("hardpuzzle3", "160107", "9dffb3f6fc8daf2bf4a27b4b43745b93", 796682),
	ENTRY1("haroldnight2003", "141007", "ac404358f94472c2e9c8bc07596995db", 949134),
	ENTRY1("killerheadache", "121231", "ab18f553a035242a15f5a39f16f03173", 1382924),
	ENTRY1("herecomestreble", "160619", "573a53ce59a78c09bdfcf4f09b5cfd60", 666278),
	ENTRY1("hobbitglulx", "010911", "87212129f54fd80c1f31104eee222f2c", 183642),
	ENTRY1("hungerdaemon","141202", "9908fa1aad277bbc968587ea388d179f", 1496460),
	ENTRY1("illum", "180228", "f6babe0280f8334036751a2a943de1a9", 7233750),
	ENTRY1("illum", "181001", "c2b6e0ab32c4035a903926448332e3a9", 7241942),
	ENTRY1("illum", "190221", "5220fec6734d7320cbe989ae8f12c2e0", 7242454),
	ENTRY1("Illwind", "130515", "3904b4080d16b1e5d56caa6df64d5887", 1057002),
	ENTRY1("ingoodcompany", "161114", "8e7d4e242f7dff5d9e9be419e2da857b", 1628586),
	ENTRY1("kerkerkruip", "140419", "879c34531bc7dbb66bad8fca651bc428", 22109534),
	ENTRY1("klaustrophobia", "110926", "d8751353ff883a1439c4c90cac2991fa", 3599478),
	ENTRY1("koa", "000001", "f70361a47c2e9571a4fdc72ce7453197", 1085696),
	ENTRY1("lastresort", "070213", "bc26a4383290d3c04657ea58841b3d91", 787200),
	ENTRY1("limeergot", "151130", "1290543b3d72115bc31201ed244b5011", 1008590),
	ENTRY1("lmstvgglulx", "080404", "9dc7716acde7bc5bdc460f11f7ad51f9", 312920),
	ENTRY1("lockkey", "1.12", "6f621089d571d2dada889e4367f4d20b", 269862),
	ENTRY1("lockdown", "150112", "556ecd86ad03658d443e8deaba126601", 1338172),
	ENTRY1("makechangeglulx", "120107", "0ee70eea03ca810bf0de3dcecfd9c741", 6456118),
	ENTRY1("mollybutterthieves", "160704", "e8d72805a49b658df517a91857a7feaf", 1870384),
	ENTRY1("moments1", "061113", "6a7092f959c8a731cb2651860a00a4eb", 684314),
	ENTRY1("moments2", "070417", "6c18999a3689234664b3daef737811ca", 13970974),
	ENTRY1("moonbaseindigo", "150101", "d31c005adf9f03febf5888b7fc5cf864", 1331372),
	ENTRY1("mugglestudies", "120314", "0053d3c68896176ae8637752f5a855ee", 1320898),
	ENTRY1("mgaeb", "110326", "9e79d4c25be31698254648579288e6dc", 676818),
	ENTRY1("mystery", "160508", "cbd8c64ebfe2c1d7da7d3739764283ae", 1127312),
	ENTRY1("narco", "1.07", "5dc6eac35d115b03f40ec61ce6e90c9d", 505840),
	ENTRY1("necronskeep", "110101", "880e7b8dc89efd3a6bd8410136e9132e", 750696),
	ENTRY1("necronskeep", "180120", "d533b9a3e11bd99f32ec7dcdccbae903", 749160),
	ENTRY1("necronskeep", "190114", "2db002f0b695a4050249c0cd822d9c7b", 1027002),
	ENTRY1("newcat", "110929", "51d263a55473d4d1ce0bceebca93a878", 795092),
	ENTRY1("nightfall", "090425", "7784b0b91d27a0995cbf0f8b2ee669bf", 1339348),
	ENTRY1("nightmare", "150927", "5a1800ab91062b1edf96671d4de15fb5", 646038),
	ENTRY1("nssri", "180606", "c8e18e3c0ea50ecab2723fa581997acc", 1376102),
	ENTRY1("oldfogey", "160512", "bb1cc12fcc2c0d606d237cb8bed8ef7e", 612406),
	ENTRY1("oliviasorphanorium", "121118", "f0719bf95ca31e2bf964ebf11628b9ba", 1279388),
	ENTRY1("oppositelyopal", "150214", "e7bbe4bca68cf243c64528b464b99ebf", 1515910),
	ENTRY1("ottumwaglulx", "021409", "1fc1da4f374493bee3a13c143beeba58", 537712),
	ENTRY1("owlconsults", "171124", "d1d4bd725f5e64a80f97cfc6e687a8e8", 287488),
	ENTRY1("oxygen", "150121", "31a6aaaf3bdfde86a93583e73d50b4fb", 927386),
	ENTRY1("patanoir", "131204", "b328b1edff8f94715898ff0a58e845f9", 877876),
	ENTRY1("phoenixfire", "190204", "1aab4fc41f54524f98988045aa6be1df", 767690),
	ENTRY1("photopiaglulx", "10274", "eab3f6371531c78b2e80803e1636da7d", 627050),
	ENTRY0("pinched", "a6087088eddc38bbed669d531993c688", 1107350),
	ENTRY1("pizzadelivery", "181115", "d47886a06ab5ec9ed256d56fefc75b8a", 620486),
	ENTRY1("playinggames", "111127", "3e907a5feabc7ef36d019c866ec084c0", 630242),
	ENTRY1("portfoliopiece", "170510", "efd348ae57ca688962388a410d273451", 636614),
	ENTRY1("psychomanteum", "161029", "e88338c8e1ace3391eee928f352c83ad", 3059478),
	ENTRY1("pythoglulx", "020223", "3bfe1fa8468e96538b084db5c5feac55", 437408),
	ENTRY1("rar", "160423", "d45b8709505785738bb6f935c6e2cb2e", 881040),
	ENTRY1("reorsbushcaveglulx", "170406 Censored", "10c52283c50482a876f7fcc19d19934e", 1377424),
	ENTRY1("reorsbushcaveglulx", "170406 Explicit", "53ed4c8cd45aea30954e1442b169368e", 1496516),
	ENTRY1("reorsbushcaveglulx", "170424 Censored", "67fa7a51a11494ae58b1cd298f99c1bc", 1377276),
	ENTRY1("reorsbushcaveglulx", "170424 Explicit", "37883e3c63a18db1bed8bc4e81d13414", 1539506),
	ENTRY1("risorgglulx", "060308", "86158d4fe6da56b253db871685f95c99", 545280),
	ENTRY1("risorgglulx", "171024", "3eb4e5aecb2c899bec5db264928fa252", 568576),
	ENTRY1("risorgglulx", "171114", "ba7417d44454c43a3fb9ffc31c5da0bc", 701928),
	ENTRY1("robinandorchid", "140602", "2561b2f1f0b9d3550e6052d6e5fa2ac3", 1210868),
	ENTRY1("rosewood", "131116", "c766929c3cc25a13b5a60f90b618d94e", 736304),
	ENTRY1("rover", "091116", "88249e5938448be487267a4b609a45e7", 1741574),
	ENTRY1("safe", "110109", "95af9e7de6e31fdeff6bd3cf7969434d", 648720),
	ENTRY1("sagebrushcactus", "100918", "de27a377b78387126b77552bccf0a085", 640246),
	ENTRY1("samfortunepi", "090510", "f177d973432b7a27302f1a79c8106f72", 706326),
	ENTRY1("scrollthief", "150729", "9c26a3dc0f4fb681bf79f681e63c0d76", 2367848),
	ENTRY1("section1awakened", "150812", "e05b999f193566771ff08679d5512143", 625112),
	ENTRY1("sensory", "000329", "7432f9e1d416034acf10e8a499368b9e", 202258),
	ENTRY1("sensory", "000329", "7c5a00524809e4402ddf0554394e81bc", 132608),
	ENTRY1("sequitur", "140813", "c7e384b1938915f17cc0b7d50f41d235", 1642480),
	ENTRY1("shapes", "000001", "a011827749eeef8afe6f6b8d5bfb78db", 1254912),
	ENTRY1("sheephere", "160416", "1de700b758ef6f975150a6bd8926880d", 621466),
	ENTRY1("shufflingaround", "150328", "00b2a517ec539936b96e84fabb91e5db", 3208092),
	ENTRY1("signalerror", "111116", "739510541192f01467b319b70ed7bf1f", 2138394),
	ENTRY0("sittm", "4a2ba3c1b9574b6292cbe361fc49af40", 409344),
	ENTRY1("six", "120805", "2705921eee09a568959584be1929b6b7", 8663464),
	ENTRY1("six", "170723", "2d1fdfe386c08fdacd620b7497bcd88f", 8661160),
	ENTRY0("smittenkittens", "c3402d5d8b94675af5e3e0069366d4fd", 1240942),
	ENTRY1("skmmc", "150116", "46aee190f69d75592d72b1e3c573b6a8", 831452),
	ENTRY1("spaceship", "090928", "e52390cba328a8c863150ce4651fa71f", 1429732),
	ENTRY1("spellbound", "160728", "c37e0e19a2fe74edc2d1df90bc97e132", 1061586),
	ENTRY1("spirI7wrak", "141218", "d7e58b86d1c6e06ecdc83ebbb7b20242", 2631214),
	ENTRY1("starlight", "151119", "ee4d2ed91518392981bf3cfd0fcf644d", 885152),
	ENTRY1("subrosa", "160324", "30e7ded8624c26c04e8361d235f42c67", 1481628),
	ENTRY1("superluminalvagranttwin", "160316", "7beb275a3e66b7b9840019caa3041723", 1162788),
	ENTRY1("tacoFiction", "130422", "766be6495cb312d8270587c4d45d7e6a", 1928530),
	ENTRY1("terminatorrobotrescue", "150214", "596b41d3ecc38bfb9a6aee085f333591", 1054550),
	ENTRY1("tcom", "121103", "67504ebc3d525f6a29fa800b6e12229d", 326226),
	ENTRY1("tcom", "121103 (No Gfx)", "24feef55d07cc46bcc5479ce580cbe3e", 246272),
	ENTRY1("duelspannedages", "100403", "4887e9c2e6df64ac85be17bedaed36f9", 628480),
	ENTRY1("equivocalingredient", "090509", "537279579b7c0dd2f5d8213a84209c7f", 1285236),
	ENTRY1("houseofmystery", "180608", "97e29a1a074ab5b46f5b7edf9914a957", 1252656),
	ENTRY1("houseofmystery", "180929", "4b34547babe73117e6575d559b71d1e5", 2486390),
	ENTRY1("kingshredspatches", "090722", "87765824be7facf6400a392633f84602", 4340676),
	ENTRY1("lostislandsofalabaz", "110524", "9f439a77eccf4813aebebbe8093e8c57", 3145932),
	ENTRY1("theabbey", "080626", "3abcc1b85a36efb73815e1cd37143210", 645274),
	ENTRY0("thehours", "2d94f14e3ce959173da1ed35502f1419", 1281774),
	ENTRY1("thehouseoffear", "111109", "f952621c0d7d8808ec4c339f0c1b3872", 1132748),
	ENTRY1("thelibrary", "141212", "a545e2f3c25715a0b693ada6407e2b54", 1201984),
	ENTRY1("themuseum", "081128", "8285ac707a9a47900c380d8af9632d1b", 3266510),
	ENTRY1("thephoenixmove", "080821", "564e3f053220cb23342a6984cfcef8f9", 611890),
	ENTRY1("rocketmanfromsea", "120507", "33c7faa1be533ce760f89da13997dbbf", 2210282),
	ENTRY1("thesimpletale", "121216", "ad56281f7fb97718269122c014230df6", 1348802),
	ENTRY1("theskycrane", "160602", "f40afca1c0252a90a614c27b39a6bd82", 626632),
	ENTRY1("thespywhoatelunch", "120102", "4d6d33ff7c740020067d85cdcb46678e", 839742),
	ENTRY1("thethiefofwovenwoods", "110513", "cf0cee73644411e8176c7320eb8b68d8", 388820),
	ENTRY1("thetinyhouse", "091210", "5e86e6852c049ac973af5175d61b60e9", 823552),
	ENTRY1("theabsenceoflaw", "170102", "210e6dc1d5c0fc1f4340ae9ee5bdcf4e", 1332522),
	ENTRY1("ascentgothictower", "140831", "5fa0426759ecc243abd54f3c1c4f6d12", 2408444),
	ENTRY1("thebox", "170813", "91ec66de5a2b6d9e9e889835857c03e7", 1371546),
	ENTRY1("thefourthriddle", "181228", "07f018d38c164615890adc44855fb15b", 1281176),
	ENTRY1("theinformal7abbreviated", "150706", "79e489ca1095835e2de90b5a9ea0812c", 611172),
	ENTRY1("theislandofdoctorwooby", "150811", "c6bf4a675821d51c1ec251ff2bfd4770", 1164724),
	ENTRY1("thelaughinggnome", "160212", "c55fc26f587526618c4baf820b33f3f4", 728918),
	ENTRY1("thelostkingdomofcodetopia", "171113", "961fcb440ebd5f7738545a2f705c9785", 747220),
	ENTRY1("themaryjaneoftomorrow", "160605", "b8842f2deb9b283cccd272c0dbfc2369", 10344070),
	ENTRY1("theoutcasts", "170312", "234a5a35fc846aca8a4363a773d032e1", 731070),
	ENTRY1("therealmofaoria", "160412", "29f1e1568486fbcc95d06c470534c233", 4466630),
	ENTRY1("therealmofaoria", "161205", "87e9e7411e535e335e580d16be255671", 6458822),
	ENTRY1("thestorm", "190107", "f0a0f037fec735bdfe770f1f171e03a8", 820842),
	ENTRY1("thetraintoabaddon", "141107", "55a4a454fba273067cc127c4f1a8ce3a", 848180),
	ENTRY1("thiefpokemon", "140111", "2bfabf36b6171ed487858c10af0ea88d", 358392),
	ENTRY1("tohellinahamper", "170412", "f12baa1762e29c9528baec31347a18b0", 973550),
	ENTRY1("transparent", "150401", "3f4e5effb8ed8f4d0c3f277bb47ba161", 11084272),
	ENTRY1("transparent", "150626 (No Sound)", "13dc495dc3ed802e663b193bd862b994", 2284454),
	ENTRY1("trialofthetnuop", "170813", "d8a34dc6c9b0e2d037d8cc3de006f42b", 616062),
	ENTRY1("trollslayer", "151112", "fa3dee31c195732ad6a13a6e0b54d625", 920230),
	ENTRY1("tryagain", "160922", "64de60e3dbc7eb492a34a0a693156659", 626116),
	ENTRY1("uglyoafs", "150403", "39ba113801d9b90d506b356f6b3ba25a", 660078),
	ENTRY1("uie", "101122", "ed892c12a8b2d65fcda5ba6a228e04ed", 2016322),
	ENTRY1("unscientificfiction", "090803", "de1c4a2bf4024eb4c0e5fee0e0fd4746", 679608),
	ENTRY1("valleyofsteel", "140330", "88311986461cec17e776d82a5ac18416", 1853024),
	ENTRY1("wand", "171118", "b824638fc1d015b0837688322839ada0", 830208),
	ENTRY1("winterstormdraco", "150928", "b4835af78525e56420f138c2e5f6806c", 812124),
	ENTRY1("wishertheurgist", "160708", "4bbe0b3a29d57d1428e6cd6cf7c97fce", 824204),
	ENTRY1("wof", "100515", "7de6ef1ecdec5066f65b1283b9203dc6", 10185552),
	ENTRY1("wordoftheday", "171129", "c45a9d68e80765ceff7654366fa47328", 4506970),
	ENTRY1("wordsofpower", "021229 (No Sound)", "487ab63bce62d7fd86852b1974ba1a1c", 465306),
	ENTRY1("wordsofpower", "021229", "dfb5064095b4d71291b81dd281d8c520", 6240896),
	ENTRY1("zorkglulx", "080504", "94839db9d8437e493a4b254e6e540359", 1020160),

	// Apollo 18+20 IF Tribute Album
	ENTRY0("apollo3glulx", "33cf75f5bcc2a28af85d83e4e3f3b846", 482978),
	ENTRY0("apollo10glulx", "ac5fe600e5cf179738af4329f71304f8", 1897372),
	ENTRY0("apollo12glulx", "bfadac2b1ac0eab7187e4a5166a72798", 883926),
	ENTRY0("apollo15glulx", "c1e23a471ff61e3846b63cc21ff9edfa", 633818),
	ENTRY0("apollo19glulx", "66b599c4aecd63caa59b00bfd5101f43", 466244),
	ENTRY0("apollo33glulx", "74457b493e101e87463a0be645d2ab65", 411726),

	// French games
	ENTRYL1("ekphrasis", "050718", "009ca5994d9e8fe6cfb400a9da00b123", 64609308, Common::FR_FRA),
	ENTRYL0("lieuxcommunsglulx", "6e18273de25a0b882b0cf01770003146", 15659070, Common::FR_FRA),
	ENTRYL1("sarvegneglulx", "061101", "518ab27b773bb51f57c6526655f38e6f", 594306, Common::FR_FRA),
	ENTRYL1("scarabeekatana", "070906", "e2ca97ca5579b544765e744964c9624f", 651590, Common::FR_FRA),
	ENTRYL1("templefeu", "070731", "73c3a0486d41a41c454108298014fac0", 2576096, Common::FR_FRA),

	// German games
	ENTRYL1("dergarten", "180510", "b90eda22c098c5d70eb2a0cb5140dbe0", 2183442, Common::DE_DEU),
	ENTRYL1("deronirischegarten", "180730", "eb41961e5772ca99c03ba49f6b4ceb62", 476352, Common::DE_DEU),
	ENTRYL1("matthiasclaudius", "170328", "514f28c468487b3239cb2fbc7c4a2dac", 1007368, Common::DE_DEU),
	ENTRYL1("matthiasclaudius", "171010", "437460fae6cd8b57d9e9599f5c29504f", 1010696, Common::DE_DEU),
	ENTRYL1("matthiasclaudius", "180730", "bc2d409cc3ab7c65f52332d64e792bae", 1016584, Common::DE_DEU),
	ENTRYL1("morgenwirdklausur", "170423", "b71391f995becb65992561d57ed80829", 724164, Common::DE_DEU),
	ENTRYL1("morgenwirdklausur", "170430", "85a966e56c4e0fc7d10df9bc3824da95", 727492, Common::DE_DEU),
	ENTRYL1("patanoirde", "131202", "9ed40b987510c7a8b7da4386ff8879b1", 969304, Common::DE_DEU),

	// Italian games
	ENTRYL1("beyondglulx", "100115", "a0cd0a410cc99aa7ff661129b8ec5de8", 1331582, Common::IT_ITA),
	ENTRYL1("pietradellaluna", "110106", "8834e0273fc730b8f6dcd38bbba2894d", 1060656, Common::IT_ITA),
	ENTRYL1("mancasolo", "398874", "de6d58b378dee41d273f7bb3c5da4220", 978440, Common::IT_ITA),
	ENTRYL1("schizo", "180907", "3531f6066802f53f9b095b5221fac4d2", 6198900, Common::IT_ITA),
	ENTRYL1("schizo", "180907", "30ff0bffbe7e1c11ea4a7ec30e0b8c76", 194560, Common::IT_ITA),
	ENTRYL1("snuff", "180827", "1005bf49b80982997ed3b0930c390d5d", 135168, Common::IT_ITA),
	ENTRYL1("villamorganaglulx", "090404", "88feac9efb31e7e6bd832bda02ff0cfa", 1263196, Common::IT_ITA),

	// Spanish games
	ENTRYL1("alienlaaventura", "081124", "e09c0e91e53a07c768eb473deae9619c", 6884846, Common::ES_ESP),
	ENTRYL1("conrumbo", "010527", "024946d9d10190694d90dedd34ab648e", 127744, Common::ES_ESP),
	ENTRYL1("dracula1glulx", "071227", "a2266f816a8e6afa324ad98e8ddb707b", 467354, Common::ES_ESP),
	ENTRYL1("dracula2glulx", "080819", "c9ff350c10f4ef88db667e58a3696938", 715450, Common::ES_ESP),
	ENTRYL1("elultimohogarglulx", "021225", "08d4168a767dce4899640a000d2809d8", 663576, Common::ES_ESP),
	ENTRYL1("hhorcusglulx", "100818", "48e7d8f6cd53506778e035eeab6c545c", 4191072, Common::ES_ESP),
	ENTRYL1("kerulenglulx", "090720", "0f4c8d5fb20666d5e66da025c3167285", 6842790, Common::ES_ESP),
	ENTRYL1("lanochedelensayo", "100122", "23845407e62d47b5d51267492137e05e", 2527892, Common::ES_ESP),
	ENTRYL0("legado", "3f5652cfb07d22c1cf668c33fc92a611", 513472, Common::ES_ESP),
	ENTRYL1("regente", "021129", "7c8608e214821c55bc9224ccfd5beb44", 273092, Common::ES_ESP),
	ENTRYL0("rur", "4d7dab1227494292f37107da1729392e", 3432966, Common::ES_ESP),
	ENTRYL1("rur", "Text Only", "de15e8cdd8523c774b66950a0232a0f9", 413184, Common::ES_ESP),

	// Swedish games
	ENTRYL1("drakmagiglulx", "080419", "93db2e43fafb22b9e4d10f7d6f3a5136", 203630, Common::SE_SWE),
	ENTRYL1("vanyarglulx", "030613", "4a80396f31f9cced2b6689341ac5d2cc", 278780, Common::SE_SWE),

	TABLE_END_MARKER
};

} // End of namespace Glulxe
} // End of namespace Glk
