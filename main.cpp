#include <iostream>
#include <ncurses.h>
#include <clocale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	
	// 0 represents null space
	// 1 represents wall
	// 2 represents box
	// 3 represents destination
	// 4 represents outside
	// 5 represents character
	// 6 represents box on destination
	
	int map1[10][10] = {
		{4, 4, 1, 1, 1, 1, 4, 4, 4, 4},
		{4, 4, 1, 3, 0, 1, 1, 4, 4, 4},
		{4, 4, 1, 3, 0, 0, 1, 4, 4, 4},
		{4, 4, 1, 3, 0, 2, 1, 4, 4, 4},
		{4, 4, 1, 1, 2, 0, 1, 1, 1, 4},
		{4, 4, 4, 1, 0, 2, 0, 0, 1, 4},
		{4, 4, 4, 1, 0, 0, 0, 0, 1, 4},
		{4, 4, 4, 1, 0, 0, 1, 1, 1, 4},
		{4, 4, 4, 1, 1, 1, 1, 4, 4, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4}
    	};

	WINDOW *win1; // game창
	WINDOW *win2; // step 횟수
	WINDOW *win3; // push 횟수
	WINDOW *win4; // 완료창

	initscr();
	resize_term(50, 50);
	start_color();
	init_pair(10, COLOR_BLACK, COLOR_WHITE);
	init_pair(0, COLOR_BLACK, COLOR_BLUE);
	init_pair(1, COLOR_BLACK, COLOR_GREEN);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	init_pair(4, COLOR_BLACK, COLOR_WHITE);
	
	
	

	border('|', '|', '-', '-', '+', '+', '+', '+');
	mvprintw(1, 9, "Welcome To The Push Box Game!");
	mvprintw(2, 12, "Press Any Key To Start");
	refresh(); // 화면 업데이트. 화면 실제 출력
	getch();
	mvprintw(1, 9, "         PUSH BOX GAME          ");
	mvprintw(2, 1, "------------------------------------------------");


	win1 = newwin(12, 12, 16, 19);
	wbkgd(win1, COLOR_PAIR(10));
	wattron(win1, COLOR_PAIR(10));;
	wborder(win1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');


	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map1[i][j] == 0) {
				attron(COLOR_PAIR(0));
				mvprintw(17 + i, 20 + j, " ");
				attroff(COLOR_PAIR(0));
			}
			else if (map1[i][j] == 1) {
				attron(COLOR_PAIR(1));
				mvprintw(17 + i, 20 + j, " ");
				attroff(COLOR_PAIR(1));
			}
			else if (map1[i][j] == 2) { // 상자
				attron(COLOR_PAIR(2));
				mvprintw(17 + i, 20 + j, "\u2752");
				attroff(COLOR_PAIR(2));
			}
			else if (map1[i][j] == 3) { // 목적지
				attron(COLOR_PAIR(3));
				mvprintw(17 + i, 20 + j, "\u2B1A");
				attroff(COLOR_PAIR(3));
			}
			else if (map1[i][j] == 4) {
				attron(COLOR_PAIR(4));
				mvprintw(17 + i, 20 + j, " ");				
				attroff(COLOR_PAIR(4));
			}
		}

	}
	wrefresh(win1); // 화면 업데이트. win1 화면 실제 출력
	getch();
	delwin(win1); // win1 소멸
	
	win4 = newwin(20, 30, 13, 10);
	wbkgd(win4, COLOR_PAIR(10));
	wattron(win4, COLOR_PAIR(3));
	mvwprintw(win4, 9, 11, "SUCCESS!");
	wborder(win4, '@','@','@','@','@','@','@','@');
	wrefresh(win4);
	getch();
	delwin(win4);

	
	endwin(); // ncurses mode 종료
	
	return 0;
}
