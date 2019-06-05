#include "map.h"

Map::Map(vector<vector<int>> vector)
{
    this->vec = vector;
    this->default_map = vector;
}

void Map::setElement(int x, int y, int input)
{
    this->vec[x][y] = input;
}

void Map::setCharacter(int x, int y)
{
    this->vec[x][y] = CHARACTER;
}

/*
Unicode 72 represents 'up'
Unicode 75 represents 'left'
Unicode 77 represents 'right'
Unicode 80 represents 'down'
*/


// arrow input -> move

// front of wall, or over 2 box -> don't move

// front of one box and not blocked -> move with box

int Map::do_nothing()
{
    return 0;
}

void Map::find_character()
{
    int row, col;
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            if (vec[i][j]==5)
            {
                row = i;
                col = j;
            }
        }
    }
    location_of_character.clear();
    location_of_character.push_back(row);
    location_of_character.push_back(col);
}

void Map::move(char arrow)
{
    find_character();
    int char_row = location_of_character[0]; // 캐릭터의 현재 위치(행 값)
    int char_col = location_of_character[1]; // 캐릭터의 현재 위치(열 값)
    switch(arrow)
    {   
        case 72: // ↑ 입력
            int loc = vec[char_row][char_col]; // 캐릭터의 현재 위치
            if(vec[char_row-1][char_col]==NULL_SPACE) // 캐릭터 위쪽이 비어있으면 캐릭터를 위쪽으로 한칸 전진
            {
                setCharacter(char_row-1, char_col);
                setElement(char_row, char_col, default_map[char_row][char_col]);
            }
            else if(vec[char_row-1][char_col]==WALL) // 캐릭터 위쪽이 벽이면
            {
                do_nothing(); // 캐릭터 이동 불가능
            }
            else if(vec[char_row-1][char_col]==BOX) // 캐릭터 위쪽이 박스일 때
            {
                if((vec[char_row-2][char_col]==WALL)||(vec[char_row-2][char_col]==BOX)) // 박스 위쪽이 벽이거나 박스이면
                {
                    do_nothing(); // 캐릭터 이동 불가능
                }
                else if(vec[char_row-2][char_col]==NULL_SPACE) // 박스 앞이 비어있으면
                {
                    setElement(char_row, char_col, default_map[char_row][char_col]); // 캐릭터 있던 곳은 기본 값
                    setCharacter(char_row-1, char_col); // 캐릭터와 박스가 함께 위쪽으로 이동
                    setElement(char_row-2, char_col, BOX);
                }
                else if(vec[char_row-2][char_col]==DEST) // 박스 앞이 목적지이면
                {
                    setElement(char_row, char_col, default_map[char_row][char_col]); // 캐릭터 있던 곳은 기본 값
                    setCharacter(char_row-1, char_col); // 캐릭터와 박스가 함께 위쪽으로 이동
                    setElement(char_row-2, char_col, BOX_ON_DEST); // 목적지에 박스가 들어갔음을 표시
                }
            }
        
        case 75: // <- 입력
            int loc = vec[char_row][char_col]; // 캐릭터의 현재 위치
            if(vec[char_row][char_col-1]==NULL_SPACE) // 캐릭터 왼쪽이 비어있으면 캐릭터를 왼쪽으로 한칸 전진
            {
                setCharacter(char_row, char_col-1);
                setElement(char_row, char_col, default_map[char_row][char_col]);
            }
            else if(vec[char_row][char_col-1]==WALL) // 캐릭터 왼쪽이 벽이면
            {
                do_nothing(); // 캐릭터 이동 불가능
            }
            else if(vec[char_row][char_col-1]==BOX) // 캐릭터 왼쪽이 박스일 때
            {
                if((vec[char_row][char_col-2]==WALL)||(vec[char_row][char_col-2]==BOX)) // 박스 왼쪽이 벽이거나 박스이면
                {
                    do_nothing(); // 캐릭터 이동 불가능
                }
                else if(vec[char_row][char_col-2]==NULL_SPACE) // 박스 앞이 비어있으면
                {
                    setElement(char_row, char_col, default_map[char_row][char_col]); // 캐릭터 있던 곳은 기본 값
                    setCharacter(char_row, char_col-1); // 캐릭터와 박스가 함께 왼쪽으로 이동
                    setElement(char_row, char_col-2, BOX);
                }
                else if(vec[char_row][char_col-2]==DEST) // 박스 앞이 목적지이면
                {
                    setElement(char_row, char_col, default_map[char_row][char_col]); // 캐릭터 있던 곳은 기본 값
                    setCharacter(char_row, char_col-1); // 캐릭터와 박스가 함께 왼쪽으로 이동
                    setElement(char_row, char_col-2, BOX_ON_DEST); // 목적지에 박스가 들어갔음을 표시
                }
            }

        case 77: // -> 입력
            int loc = vec[char_row][char_col]; // 캐릭터의 현재 위치
            if(vec[char_row][char_col+1]==NULL_SPACE) // 캐릭터 오른쪽이 비어있으면 캐릭터를 오른쪽으로 한칸 전진
            {
                setCharacter(char_row, char_col+1);
                setElement(char_row, char_col, default_map[char_row][char_col]);
            }
            else if(vec[char_row][char_col+1]==WALL) // 캐릭터 오른쪽이 벽이면
            {
                do_nothing(); // 캐릭터 이동 불가능
            }
            else if(vec[char_row][char_col+1]==BOX) // 캐릭터 오른쪽이 박스일 때
            {
                if((vec[char_row][char_col+2]==WALL)||(vec[char_row][char_col+2]==BOX)) // 박스 오른쪽이 벽이거나 박스이면
                {
                    do_nothing(); // 캐릭터 이동 불가능
                }
                else if(vec[char_row][char_col+2]==NULL_SPACE) // 박스 앞이 비어있으면
                {
                    setElement(char_row, char_col, default_map[char_row][char_col]); // 캐릭터 있던 곳은 기본 값
                    setCharacter(char_row, char_col+1); // 캐릭터와 박스가 함께 오른쪽으로 이동
                    setElement(char_row, char_col+2, BOX);
                }
                else if(vec[char_row][char_col+2]==DEST) // 박스 앞이 목적지이면
                {
                    setElement(char_row, char_col, default_map[char_row][char_col]); // 캐릭터 있던 곳은 기본 값
                    setCharacter(char_row, char_col+1); // 캐릭터와 박스가 함께 오른쪽으로 이동
                    setElement(char_row, char_col+2, BOX_ON_DEST); // 목적지에 박스가 들어갔음을 표시
                }
            }
        
        case 80: // ↓ 입력
            int loc = vec[char_row][char_col]; // 캐릭터의 현재 위치
            if(vec[char_row+1][char_col]==NULL_SPACE) // 캐릭터 아래쪽이 비어있으면 캐릭터를 아래쪽으로 한칸 전진
            {
                setCharacter(char_row+1, char_col);
                setElement(char_row, char_col, default_map[char_row][char_col]);
            }
            else if(vec[char_row+1][char_col]==WALL) // 캐릭터 아래쪽이 벽이면
            {
                do_nothing(); // 캐릭터 이동 불가능
            }
            else if(vec[char_row+1][char_col]==BOX) // 캐릭터 아래쪽이 박스일 때
            {
                if((vec[char_row+2][char_col]==WALL)||(vec[char_row+2][char_col]==BOX)) // 박스 아래쪽이 벽이거나 박스이면
                {
                    do_nothing(); // 캐릭터 이동 불가능
                }
                else if(vec[char_row+2][char_col]==NULL_SPACE) // 박스 앞이 비어있으면
                {
                    setElement(char_row, char_col, default_map[char_row][char_col]); // 캐릭터 있던 곳은 기본 값
                    setCharacter(char_row+1, char_col); // 캐릭터와 박스가 함께 아래쪽으로 이동
                    setElement(char_row+2, char_col, BOX);
                }
                else if(vec[char_row+2][char_col]==DEST) // 박스 앞이 목적지이면
                {
                    setElement(char_row, char_col, default_map[char_row][char_col]); // 캐릭터 있던 곳은 기본 값
                    setCharacter(char_row+1, char_col); // 캐릭터와 박스가 함께 아래쪽으로 이동
                    setElement(char_row+2, char_col, BOX_ON_DEST); // 목적지에 박스가 들어갔음을 표시
                }
            }
            
    }
}




Map map1({
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
        });

Map map2({
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
        });

Map map3({
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
        });

Map map4({
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
        });

Map map5({
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
        {4, 1, 1, 1, 1, 4, 4, 4, 4, 4},
		{4, 1, 0, 0, 1, 1, 1, 1, 4, 4},
		{4, 1, 0, 0, 0, 0, 0, 1, 1, 4},
		{1, 1, 0, 1, 1, 0, 0, 0, 1, 4},
		{1, 3, 0, 3, 1, 0, 0, 2, 1, 1},
		{1, 0, 0, 0, 1, 0, 2, 2, 0, 1},
		{1, 0, 0, 3, 1, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4}
    });