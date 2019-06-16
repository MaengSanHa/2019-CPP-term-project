#include <ncurses.h>
#include <clocale>
#include "Map.cpp"


/*
	void PrintMap() 
	{
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (map1.map[i][j] == 0) {
					attron(COLOR_PAIR(0));
					mvprintw(8 + i, 11 + j, " ");
					attroff(COLOR_PAIR(0));
				}
				else if (map1.map[i][j] == 1) {
					attron(COLOR_PAIR(1));
					mvprintw(8 + i, 11 + j, " ");
					attroff(COLOR_PAIR(1));
				}
				else if (map1.map[i][j] == 2) {
					attron(COLOR_PAIR(2));
					mvprintw(8 + i, 11 + j, "#");
					attroff(COLOR_PAIR(2));
				}
				else if (map1.map[i][j] == 3) {
					attron(COLOR_PAIR(3));
					mvprintw(8 + i, 11 + j, "$");
					attroff(COLOR_PAIR(3));
				}
				else if (map1.map[i][j] == 4) {
					attron(COLOR_PAIR(4));
					mvprintw(8 + i, 11 + j, " ");				
					attroff(COLOR_PAIR(4));
				}
				else if (map1.map[i][j] == 5) {
					attron(COLOR_PAIR(4));
					mvprintw(8 + i, 11 + j, "C");				
					attroff(COLOR_PAIR(4));
				}
			}

		}
	
	}

*/
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
	

	int map[10][10] = { // 35  44 55
		{4, 4, 1, 1, 1, 1, 4, 4, 4, 4},
		{4, 4, 1, 3, 0, 1, 1, 4, 4, 4},
		{4, 4, 1, 3, 0, 0, 1, 4, 4, 4},
		{4, 4, 1, 3, 0, 0, 1, 4, 4, 4},
		{4, 4, 1, 1, 0, 0, 1, 1, 1, 4},
		{4, 4, 4, 1, 0, 0, 0, 0, 1, 4},
		{4, 4, 4, 1, 0, 0, 0, 0, 1, 4},
		{4, 4, 4, 1, 0, 0, 1, 1, 1, 4},
		{4, 4, 4, 1, 1, 1, 1, 4, 4, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4}
    };
    
    int mapTwo[10][10] = {
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 1, 1, 1, 1, 1, 4, 4, 4},
		{4, 4, 1, 0, 0, 0, 1, 4, 4, 4},
		{4, 4, 1, 3, 3, 3, 1, 4, 4, 4},
		{4, 4, 1, 0, 0, 0, 1, 1, 4 ,4},
		{4, 4, 1, 0, 0, 0, 0, 1, 4, 4},
		{4 ,4, 1, 0, 0, 0, 0, 1, 4, 4},
		{4, 4, 1, 1, 1, 1, 1, 1, 4, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4}
	};
    
    Map map1(map);
    Map map2(mapTwo);

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

	// 박스랑 캐릭터 초기 위치 설정
	map1.setElement(3, 5, 2);
	map1.setElement(4, 4, 2);
	map1.setElement(5, 5, 2);
	map1.setCharacter(2, 4);
 	
 	// 처음 맵 출력 
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map1.map[i][j] == 0) {
				attron(COLOR_PAIR(0));
				mvprintw(8 + i, 11 + j, " ");
				attroff(COLOR_PAIR(0));
			}
			else if (map1.map[i][j] == 1) {
				attron(COLOR_PAIR(1));
				mvprintw(8 + i, 11 + j, " ");
				attroff(COLOR_PAIR(1));
			}
			else if (map1.map[i][j] == 2) {
				attron(COLOR_PAIR(2));
				mvprintw(8 + i, 11 + j, "#");
				attroff(COLOR_PAIR(2));
			}
			else if (map1.map[i][j] == 3) {
				attron(COLOR_PAIR(3));
				mvprintw(8 + i, 11 + j, "$");
				attroff(COLOR_PAIR(3));
			}
			else if (map1.map[i][j] == 4) {
				attron(COLOR_PAIR(4));
				mvprintw(8 + i, 11 + j, " ");				
				attroff(COLOR_PAIR(4));
			}
			else if (map1.map[i][j] == 5) {
				attron(COLOR_PAIR(4));
				mvprintw(8 + i, 11 + j, "C");				
				attroff(COLOR_PAIR(4));
			}
		}
	}


	refresh();

	curs_set(0);
	int ch;
	while (true) {
		keypad(stdscr, true);
		//PrintMap();
		ch = getch();
		if (ch == KEY_UP) {
			map1.move(72); // 위
			// 바뀔 때마다 맵 출력
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (map1.map[i][j] == 0) {
						attron(COLOR_PAIR(0));
						mvprintw(8 + i, 11 + j, " ");
						attroff(COLOR_PAIR(0));
					}
					else if (map1.map[i][j] == 1) {
						attron(COLOR_PAIR(1));
						mvprintw(8 + i, 11 + j, " ");
						attroff(COLOR_PAIR(1));
					}
					else if (map1.map[i][j] == 2) {
						attron(COLOR_PAIR(2));
						mvprintw(8 + i, 11 + j, "#");
						attroff(COLOR_PAIR(2));
					}
					else if (map1.map[i][j] == 3) {
						attron(COLOR_PAIR(3));
						mvprintw(8 + i, 11 + j, "$");
						attroff(COLOR_PAIR(3));
					}
					else if (map1.map[i][j] == 4) {
						attron(COLOR_PAIR(4));
						mvprintw(8 + i, 11 + j, " ");				
						attroff(COLOR_PAIR(4));
					}
					else if (map1.map[i][j] == 5) {
						attron(COLOR_PAIR(4));
						mvprintw(8 + i, 11 + j, "C");				
						attroff(COLOR_PAIR(4));
					}
				}

			}

		}
		else if (ch == KEY_LEFT) {
			map1.move(75); // 왼쪽 
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (map1.map[i][j] == 0) {
						attron(COLOR_PAIR(0));
						mvprintw(8 + i, 11 + j, " ");
						attroff(COLOR_PAIR(0));
					}
					else if (map1.map[i][j] == 1) {
						attron(COLOR_PAIR(1));
						mvprintw(8 + i, 11 + j, " ");
						attroff(COLOR_PAIR(1));
					}
					else if (map1.map[i][j] == 2) {
						attron(COLOR_PAIR(2));
						mvprintw(8 + i, 11 + j, "#");
						attroff(COLOR_PAIR(2));
					}
					else if (map1.map[i][j] == 3) {
						attron(COLOR_PAIR(3));
						mvprintw(8 + i, 11 + j, "$");
						attroff(COLOR_PAIR(3));
					}
					else if (map1.map[i][j] == 4) {
						attron(COLOR_PAIR(4));
						mvprintw(8 + i, 11 + j, " ");				
						attroff(COLOR_PAIR(4));
					}
					else if (map1.map[i][j] == 5) {
						attron(COLOR_PAIR(4));
						mvprintw(8 + i, 11 + j, "C");				
						attroff(COLOR_PAIR(4));
					}
				}

			}
		}
		else if (ch == KEY_RIGHT) {
			map1.move(77); // 오른쪽 
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (map1.map[i][j] == 0) {
						attron(COLOR_PAIR(0));
						mvprintw(8 + i, 11 + j, " ");
						attroff(COLOR_PAIR(0));
					}
					else if (map1.map[i][j] == 1) {
						attron(COLOR_PAIR(1));
						mvprintw(8 + i, 11 + j, " ");
						attroff(COLOR_PAIR(1));
					}
					else if (map1.map[i][j] == 2) {
						attron(COLOR_PAIR(2));
						mvprintw(8 + i, 11 + j, "#");
						attroff(COLOR_PAIR(2));
					}
					else if (map1.map[i][j] == 3) {
						attron(COLOR_PAIR(3));
						mvprintw(8 + i, 11 + j, "$");
						attroff(COLOR_PAIR(3));
					}
					else if (map1.map[i][j] == 4) {
						attron(COLOR_PAIR(4));
						mvprintw(8 + i, 11 + j, " ");				
						attroff(COLOR_PAIR(4));
					}
					else if (map1.map[i][j] == 5) {
						attron(COLOR_PAIR(4));
						mvprintw(8 + i, 11 + j, "C");				
						attroff(COLOR_PAIR(4));
					}
				}

			}
		}
		else if (ch == KEY_DOWN) {
			map1.move(80); // 아래
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (map1.map[i][j] == 0) {
						attron(COLOR_PAIR(0));
						mvprintw(8 + i, 11 + j, " ");
						attroff(COLOR_PAIR(0));
					}
					else if (map1.map[i][j] == 1) {
						attron(COLOR_PAIR(1));
						mvprintw(8 + i, 11 + j, " ");
						attroff(COLOR_PAIR(1));
					}
					else if (map1.map[i][j] == 2) {
						attron(COLOR_PAIR(2));
						mvprintw(8 + i, 11 + j, "#");
						attroff(COLOR_PAIR(2));
					}
					else if (map1.map[i][j] == 3) {
						attron(COLOR_PAIR(3));
						mvprintw(8 + i, 11 + j, "$");
						attroff(COLOR_PAIR(3));
					}
					else if (map1.map[i][j] == 4) {
						attron(COLOR_PAIR(4));
						mvprintw(8 + i, 11 + j, " ");				
						attroff(COLOR_PAIR(4));
					}
					else if (map1.map[i][j] == 5) {
						attron(COLOR_PAIR(4));
						mvprintw(8 + i, 11 + j, "C");				
						attroff(COLOR_PAIR(4));
					}
				}

			}
		}	
	}

//두번째맵
	getch();
	mvprintw(1, 9, "           Level 2           ");
	mvprintw(2, 12, "                       ");

	win2 = newwin(12, 12, 7, 10);
	
		
	wattron(win2, COLOR_PAIR(10));;
	wborder(win2, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	//wbkgd(win1, 'M');
	wrefresh(win2); // 화면 업데이트. win1 화면 실제 출력

	// 박스랑 캐릭터 초기 위치 설정
	map2.setElement(4, 3, 2);
	map2.setElement(4, 4, 2);
	map2.setElement(4, 5, 2);
	map2.setCharacter(6, 4);
 	
 	// 처음 맵 출력 
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map2.map[i][j] == 0) {
				attron(COLOR_PAIR(0));
				mvprintw(8 + i, 11 + j, " ");
				attroff(COLOR_PAIR(0));
			}
			else if (map2.map[i][j] == 1) {
				attron(COLOR_PAIR(1));
				mvprintw(8 + i, 11 + j, " ");
				attroff(COLOR_PAIR(1));
			}
			else if (map2.map[i][j] == 2) {
				attron(COLOR_PAIR(2));
				mvprintw(8 + i, 11 + j, "#");
				attroff(COLOR_PAIR(2));
			}
			else if (map2.map[i][j] == 3) {
				attron(COLOR_PAIR(3));
				mvprintw(8 + i, 11 + j, "$");
				attroff(COLOR_PAIR(3));
			}
			else if (map2.map[i][j] == 4) {
				attron(COLOR_PAIR(4));
				mvprintw(8 + i, 11 + j, " ");				
				attroff(COLOR_PAIR(4));
			}
			else if (map2.map[i][j] == 5) {
				attron(COLOR_PAIR(4));
				mvprintw(8 + i, 11 + j, "C");				
				attroff(COLOR_PAIR(4));
			}
		}
	}


	refresh();

	curs_set(0);
	int ch2;
	while (true) {
		keypad(stdscr, true);
		//PrintMap();
		ch2 = getch();
		if (ch2 == KEY_UP) {
			map2.move(72); // 위
			// 바뀔 때마다 맵 출력
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (map2.map[i][j] == 0) {
						attron(COLOR_PAIR(0));
						mvprintw(8 + i, 11 + j, " ");
						attroff(COLOR_PAIR(0));
					}
					else if (map2.map[i][j] == 1) {
						attron(COLOR_PAIR(1));
						mvprintw(8 + i, 11 + j, " ");
						attroff(COLOR_PAIR(1));
					}
					else if (map2.map[i][j] == 2) {
						attron(COLOR_PAIR(2));
						mvprintw(8 + i, 11 + j, "#");
						attroff(COLOR_PAIR(2));
					}
					else if (map2.map[i][j] == 3) {
						attron(COLOR_PAIR(3));
						mvprintw(8 + i, 11 + j, "$");
						attroff(COLOR_PAIR(3));
					}
					else if (map2.map[i][j] == 4) {
						attron(COLOR_PAIR(4));
						mvprintw(8 + i, 11 + j, " ");				
						attroff(COLOR_PAIR(4));
					}
					else if (map2.map[i][j] == 5) {
						attron(COLOR_PAIR(4));
						mvprintw(8 + i, 11 + j, "C");				
						attroff(COLOR_PAIR(4));
					}
				}
			}
		}
		else if (ch2 == KEY_LEFT) {
			map2.move(75); // 왼쪽 
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (map2.map[i][j] == 0) {
						attron(COLOR_PAIR(0));
						mvprintw(8 + i, 11 + j, " ");
						attroff(COLOR_PAIR(0));
					}
					else if (map2.map[i][j] == 1) {
						attron(COLOR_PAIR(1));
						mvprintw(8 + i, 11 + j, " ");
						attroff(COLOR_PAIR(1));
					}
					else if (map2.map[i][j] == 2) {
						attron(COLOR_PAIR(2));
						mvprintw(8 + i, 11 + j, "#");
						attroff(COLOR_PAIR(2));
					}
					else if (map2.map[i][j] == 3) {
						attron(COLOR_PAIR(3));
						mvprintw(8 + i, 11 + j, "$");
						attroff(COLOR_PAIR(3));
					}
					else if (map2.map[i][j] == 4) {
						attron(COLOR_PAIR(4));
						mvprintw(8 + i, 11 + j, " ");				
						attroff(COLOR_PAIR(4));
					}
					else if (map2.map[i][j] == 5) {
						attron(COLOR_PAIR(4));
						mvprintw(8 + i, 11 + j, "C");				
						attroff(COLOR_PAIR(4));
					}
				}
			}
		}
		else if (ch2 == KEY_RIGHT) {
			map2.move(77); // 오른쪽 
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (map2.map[i][j] == 0) {
						attron(COLOR_PAIR(0));
						mvprintw(8 + i, 11 + j, " ");
						attroff(COLOR_PAIR(0));
					}
					else if (map2.map[i][j] == 1) {
						attron(COLOR_PAIR(1));
						mvprintw(8 + i, 11 + j, " ");
						attroff(COLOR_PAIR(1));
					}
					else if (map2.map[i][j] == 2) {
						attron(COLOR_PAIR(2));
						mvprintw(8 + i, 11 + j, "#");
						attroff(COLOR_PAIR(2));
					}
					else if (map2.map[i][j] == 3) {
						attron(COLOR_PAIR(3));
						mvprintw(8 + i, 11 + j, "$");
						attroff(COLOR_PAIR(3));
					}
					else if (map2.map[i][j] == 4) {
						attron(COLOR_PAIR(4));
						mvprintw(8 + i, 11 + j, " ");				
						attroff(COLOR_PAIR(4));
					}
					else if (map2.map[i][j] == 5) {
						attron(COLOR_PAIR(4));
						mvprintw(8 + i, 11 + j, "C");				
						attroff(COLOR_PAIR(4));
					}
				}
			}
		}
		else if (ch2 == KEY_DOWN) {
			map2.move(80); // 아래
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (map2.map[i][j] == 0) {
						attron(COLOR_PAIR(0));
						mvprintw(8 + i, 11 + j, " ");
						attroff(COLOR_PAIR(0));
					}
					else if (map2.map[i][j] == 1) {
						attron(COLOR_PAIR(1));
						mvprintw(8 + i, 11 + j, " ");
						attroff(COLOR_PAIR(1));
					}
					else if (map2.map[i][j] == 2) {
						attron(COLOR_PAIR(2));
						mvprintw(8 + i, 11 + j, "#");
						attroff(COLOR_PAIR(2));
					}
					else if (map2.map[i][j] == 3) {
						attron(COLOR_PAIR(3));
						mvprintw(8 + i, 11 + j, "$");
						attroff(COLOR_PAIR(3));
					}
					else if (map2.map[i][j] == 4) {
						attron(COLOR_PAIR(4));
						mvprintw(8 + i, 11 + j, " ");				
						attroff(COLOR_PAIR(4));
					}
					else if (map2.map[i][j] == 5) {
						attron(COLOR_PAIR(4));
						mvprintw(8 + i, 11 + j, "C");				
						attroff(COLOR_PAIR(4));
					}
				}
			}
		}	
	}


	getch();
	delwin(win2); // win1 소멸
	endwin(); // ncurses mode 종료
	
	return 0;
}
