#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Header ?     -> library or API
// API ?        -> application programming Interface
// Interface ?  -> 사용자가 내부구조/원리를 알지 못하더라도 사용할 수 있게 해줌.
// Library ?    -> API와 달리 standard함. / 이익창출 X.
// Header ?     -> C에서의 독자적인 Library의 이름
// unistd는 unix에서만 가능한 header
// ncurses는 따로 설치한 API

#define DINO_HEIGHT	  13
#define CACTUS_HEIGHT 5
#define CACTUS_SPEED  3
#define GRAVITY		  3
#define CELLING		  0
#define SPACE		  32
#define ENTER		  10
// define 은 전처리/preprocess [치환] 라고도 불림...

void DrawDinosaur(int);
// Linix syscall 을 overriding 해서 쓸거임.
int _kbhit(void);
int GetKeyDown();
void DrawCactus(int, int);

int GetKeyDown() {
	if (_kbhit()) {
		return getch();
	}
}
int _kbhit() {
	struct timeval tv = {0L, 0L};
	fd_set fds;

	FD_ZERO(&fds);
	FD_SET(0, &fds);

	return select(1, &fds, NULL, NULL, &tv);
}
void DrawDinorsaur(int dinosaurHead) {

	move(dinosaurHead, 0);
	static bool legDraw = true;

	printw("        &&&&&&& \n");
	printw("       && &&&&&&\n");
	printw("       &&&&&&&&&\n");
	printw("&      &&&      \n");
	printw("&&     &&&&&&&  \n");
	printw("&&&   &&&&&     \n");
	printw(" &&  &&&&&&&&&& \n");
	printw(" &&&&&&&&&&&    \n");
	printw("  &&&&&&&&&&    \n");
	printw("    &&&&&&&&    \n");
	printw("     &&&&&&     \n");

	if (legDraw) {
		printw("     &    &&&     \n");
		printw("     &&           ");
		legDraw = false;
	}

	else {
		printw("     &&&  &       \n");
		printw("          &&      ");
		legDraw = true;
	}
}
int main(void) {
	// main 은 어떤 언어던간에 모든 program들의 시작점. so called 시작함수

	initscr();
	// 터미널 초기화

	int winWidth = 0, winHeight = 0;
	int dinosaurHead = 0, cactusHead = 0;
	int cactusPos = 0;
	bool isJumping = false;
	bool isBottom = true;
	int getKey = 0;

	getmaxyx(stdscr, winHeight, winWidth);

	dinosaurHead = winHeight - DINO_HEIGHT;
	cactusHead = winHeight - CACTUS_HEIGHT;
	cactusPos = winWidth - 20;

	while (true) {

		getKey = GetKeyDown();

		if (ENTER == getKey) {
			break;
		}

		clear();
		DrawDinorsaur(dinosaurHead);
		usleep(100000);
		refresh();
	}

	endwin();

	return 0;
}