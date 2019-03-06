
#include <iostream>
#include "rules.h"
using namespace std;

bool is_victory(Gobang &chess) {
	char piece = (!chess.is_black) ? BLACK : WHITE;
	int ww = chess.cursor.w, hh = chess.cursor.h;

	Pos pos{ hh, ww };
	int len = 0;
	while (pos.is_in_board() && chess.board.get(pos) == piece) {
		++len;
		++pos.h; ++pos.w;
	}
	pos = { hh, ww };
	while (pos.is_in_board() && chess.board.get(pos) == piece) {
		++len;
		--pos.h; --pos.w;
	}
	if (len - 1 == 5) return true;

	pos = { hh, ww };
	len = 0;
	while (pos.is_in_board() && chess.board.get(pos) == piece) {
		++len;
		--pos.h; ++pos.w;
	}
	pos = { hh, ww };
	while (pos.is_in_board() && chess.board.get(pos) == piece) {
		++len;
		++pos.h; --pos.w;	
	}
	if (len - 1 == 5) return true;

	pos = { hh, ww };
	len = 0;
	while (pos.is_in_board() && chess.board.get(pos) == piece) {
		++len;
		++pos.w;
	}
	pos = { hh, ww };
	while (pos.is_in_board() && chess.board.get(pos) == piece) {
		++len;
		--pos.w;
	}
	if (len - 1 == 5) return true;

	pos = { hh, ww };
	len = 0;
	while (pos.is_in_board() && chess.board.get(pos) == piece) {
		++len;
		++pos.h;
	}
	pos = { hh, ww };
	while (pos.is_in_board() && chess.board.get(pos) == piece) {
		++len;
		--pos.h;
	}
	if (len - 1 == 5) return true;
	return false;
}
