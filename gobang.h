#ifndef GOBANG_H
#define GOBANG_H
constexpr auto height = 15;
constexpr auto width = 15;
constexpr auto BLACK = '*';
constexpr auto WHITE = 'O';
constexpr auto SPACE = '+';
constexpr auto CURSOR = 'X';
constexpr auto WALL = '#';
constexpr auto cursor_init_h = 8;
constexpr auto cursor_init_w = 8;

typedef enum { Set = 'j', Up = 'w', Left = 'a', Down = 's', Right = 'd', } Command;

struct Pos {
	int h;
	int w;
	inline bool is_in_board() const { return 1 <= h && h <= height && 1 <= w && w <= width; }
};


struct map {
	char board[height + 2][width + 2];

	char ( & operator[](size_t n)) [width + 2] { return board[n]; }
	inline char & get(Pos pos) { return board[pos.h][pos.w]; }
};

struct Gobang {
	map board;

	Pos cursor;

	bool is_black;
	bool game_over;

	Gobang(bool is_black_, Pos cur);
	void act(Command c);
	void refresh(void);
};
#endif // !CHESS_H