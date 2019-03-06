#include <iostream>
#include <conio.h>
#include "gobang.h"
#include "rules.h"
using namespace std;

void loop(void) {
	Gobang chess(true, { cursor_init_h, cursor_init_w });
	Command c;
	do {
		chess.refresh();
		if (c = (Command)getch()) {
			if (chess.game_over) continue;
			chess.act(c);
			if (is_victory(chess)) chess.game_over = true;
		}
	} while (true);
}

int main()
{
	loop();
}