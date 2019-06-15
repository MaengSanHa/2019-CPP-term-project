#include <ncurses.h>
#include <clocale>
#include "Map.h"

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
	
	int map({
		{4, 4, 1, 1, 1, 1, 4, 4, 4, 4},
		{4, 4, 1, 3, 0, 1, 1, 4, 4, 4},
		{4, 4, 1, 3, 5, 0, 1, 4, 4, 4},
		{4, 4, 1, 3, 0, 2, 1, 4, 4, 4},
		{4, 4, 1, 1, 2, 0, 1, 1, 1, 4},
		{4, 4, 4, 1, 0, 2, 0, 0, 1, 4},
		{4, 4, 4, 1, 0, 0, 0, 0, 1, 4},
		{4, 4, 4, 1, 0, 0, 1, 1, 1, 4},
		{4, 4, 4, 1, 1, 1, 1, 4, 4, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4}
    	};
	Map map1(map);
	/*
	int map2[10][10] = {
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 1, 1, 1, 1, 1, 4, 4, 4},
		{4, 4, 1, 0, 0, 0, 1, 4, 4, 4},
		{4, 4, 1, 3, 3, 3, 1, 4, 4, 4},
		{4, 4, 1, 2, 2, 2, 1, 1, 4 ,4},
		{4, 4, 1, 0, 0, 0, 0, 1, 4, 4},
		{4 ,4, 1, 0, 0, 0, 0, 1, 4, 4},
		{4, 4, 1, 1, 1, 1, 1, 1, 4, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4}
	};

	int map3[10][10] = {
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 1, 1, 1, 1, 1, 1, 1, 1, 4},
		{4, 1, 3, 0, 0, 0, 0, 0, 1, 4},
		{4, 1, 0, 3, 2, 2, 2, 0, 1, 4},
		{4, 1, 3, 0, 0, 0, 0, 0, 1, 4},
		{4, 1, 1, 1, 1, 1, 0, 0, 1, 4},
		{4, 4, 4, 4, 4, 1, 1, 1, 1, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4}
	};

	int map4[10][10] = {
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 1, 1, 1, 1, 1, 1, 1, 4},
		{4, 4, 1, 0, 0, 0, 0, 0, 1, 4},
		{4, 4, 1, 0, 3, 2, 3, 0, 1, 4},
		{4, 4, 1, 0, 2, 3, 2, 0, 1, 4},
		{4, 4, 1, 0, 3, 2, 3, 0, 1, 4},
		{4, 4, 1, 0, 2, 3, 2, 0, 1, 4},
		{4, 4, 1, 0, 0, 0, 0, 0, 1, 4},
		{4, 4, 1, 1, 1, 1, 1, 1, 1, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4}
	};

	int map5[10][10] = {
		{4, 1, 1, 1, 1, 4, 4, 4, 4, 4},
		{4, 1, 0, 0, 1, 1, 1, 1, 4, 4},
		{4, 1, 0, 0, 0, 0, 0, 1, 1, 4},
		{1, 1, 0, 1, 1, 0, 0, 0, 1, 4},
		{1, 3, 0, 3, 1, 0, 0, 2, 1, 1},
		{1, 0, 0, 0, 1, 0, 2, 2, 0, 1},
		{1, 0, 0, 3, 1, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	*/

	WINDOW *win1; // 
	WINDOW *win2; // step 횟수
	WINDOW *win3; // push 횟수
	WINDOW *win4; // level

	initscr();
	resize_term(25, 50);
	start_color();
	init_pair(10, COLOR_BLACK, COLOR_WHITE);
	init_pair(0, COLOR_BLACK, COLOR_BLUE);
	init_pair(1, COLOR_BLACK, COLOR_GREEN);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_BLACK, COLOR_WHITE);
	
	
	

	border('|', '|', '-', '-', '+', '+', '+', '+');
	mvprintw(1, 9, "Welcome To The Push Box Game!");
	mvprintw(2, 12, "Press Any Key To Start");
	refresh(); // 화면 업데이트. 화면 실제 출력
	getch();
	mvprintw(1, 9, "           Level 1           ");
	mvprintw(2, 12, "                       ");

	win1 = newwin(12, 12, 7, 10);
	
		
	wattron(win1, COLOR_PAIR(10));;
	wborder(win1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	//wbkgd(win1, 'M');
	wrefresh(win1); // 화면 업데이트. win1 화면 실제 출력

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map1[i][j] == 0) {
				attron(COLOR_PAIR(0));
				mvprintw(8 + i, 11 + j, " ");
				attroff(COLOR_PAIR(0));
			}
			else if (map1[i][j] == 1) {
				attron(COLOR_PAIR(1));
				mvprintw(8 + i, 11 + j, " ");
				attroff(COLOR_PAIR(1));
			}
			else if (map1[i][j] == 2) { // 상자
				attron(COLOR_PAIR(2));
				mvprintw(8 + i, 11 + j, "#");
				attroff(COLOR_PAIR(2));
			}
			else if (map1[i][j] == 3) { // 목적지
				attron(COLOR_PAIR(3));
				mvprintw(8 + i, 11 + j, "$");
				attroff(COLOR_PAIR(3));
			}
			else if (map1[i][j] == 4) {
				attron(COLOR_PAIR(4));
				mvprintw(8 + i, 11 + j, " ");				
				attroff(COLOR_PAIR(4));
			}
		}

	}
	refresh();

	
	
	getch();
	delwin(win1); // win1 소멸
	endwin(); // ncurses mode 종료
	
	return 0;
}
