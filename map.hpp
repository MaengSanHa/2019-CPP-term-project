using namespace std;

/*
0 represents null space
1 represents wall
2 represents box
3 represents destination
4 represents outside
5 represents character
6 represents box on destination
*/

const int NULL_SPACE=0, WALL=1, BOX=2, DEST=3, OUTSIDE=4, CHARACTER = 5, BOX_ON_DEST=6;

class Map
{
    public:
        // Constructor
        // Default constructor
        Map();

        // Copy constructor
        Map(int map_of_stage[10][10]);

        // member functions
        void setElement(int x, int y, int input);
        void setCharacter(int x, int y); // charactor represent
        void move(char arrow);
        void find_character();
        int do_nothing();
        void countDest(); // counts number of destination
        void countBoxOnDest(); // counts number of boxes on destination

        // member variables
        int numDest; // number of destination
        int numBoxOnDest; // number of boxes on destination
        int map[10][10];
        int default_map[10][10]; // default value of map
        int location_of_character[2]; // array containing location of character
};

// 기본 생성자는 map을 빈 공간으로 채운다
Map::Map()
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            this->map[i][j] = 4;
        }
    }
}

/*
main에서 2차원 배열 map_of_stage 선언 후 map과 default_map에 복사
목적지의 갯수를 numDest에 저장
*/

Map::Map(int map_of_stage[10][10])
{

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            this->map[i][j] = map_of_stage[i][j];
        }
    }
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            this->default_map[i][j] = map_of_stage[i][j];
        }
    }
    countDest();
}

void Map::countDest()
{
    numDest = 0;
    for(int i=0; i<10; ++i)
    {
        for(int j=0; j<10; ++j)
        {
            if(this->map[i][j]==DEST)
            {
                numDest++;
            }
        }
    }
}

void Map::countBoxOnDest()
{
    numBoxOnDest = 0;
    for(int i=0; i<10; ++i)
    {
        for(int j=0; j<10; ++j)
        {
            if(this->map[i][j]==BOX_ON_DEST)
            {
                numBoxOnDest++;
            }
        }
    }
}

// map의 (x, y) 위치의 값을 input으로 지정
void Map::setElement(int x, int y, int input)
{
    this->map[x][y] = input;
}

// map상의 character를 (x,y)로 이동
void Map::setCharacter(int x, int y)
{
    this->map[x][y] = CHARACTER;
}

// if character cannot move, just return 0
int Map::do_nothing()
{
    return 0;
}

// search location of character and store it to location_of_character[][]
void Map::find_character()
{
    int row, col;
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            if (map[i][j]==5)
            {
                row = i;
                col = j;
            }
        }
    }
    location_of_character[0] = row;
    location_of_character[1] = col;
}

void Map::move(char arrow)
{
    /*  
    arrow input -> move
    front of wall, or over 2 box -> don't move
    front of one box and not blocked -> move with box
    */

    find_character(); // 캐릭터 현재 위치 탐색
    int char_row = location_of_character[0]; // 캐릭터의 현재 위치(행 값)
    int char_col = location_of_character[1]; // 캐릭터의 현재 위치(열 값)
    int*loc = new int;
    *loc = map[char_row][char_col]; // 캐릭터의 현재 위치 동적 할당
    switch(arrow)
    {   
        /*
        Unicode 72 represents 'up'
        Unicode 75 represents 'left'
        Unicode 77 represents 'right'
        Unicode 80 represents 'down'
        */
        case 72: // ↑ 입력
            if(map[char_row-1][char_col]==NULL_SPACE) // 캐릭터 위쪽이 비어있으면 캐릭터를 위쪽으로 한칸 전진
            {
                setCharacter(char_row-1, char_col);
                setElement(char_row, char_col, default_map[char_row][char_col]);
            }
            else if(map[char_row-1][char_col]==WALL) // 캐릭터 위쪽이 벽이면
            {
                do_nothing(); // 캐릭터 이동 불가능
            }
            else if(map[char_row-1][char_col]==BOX) // 캐릭터 위쪽이 박스일 때
            {
                if((map[char_row-2][char_col]==WALL)||(map[char_row-2][char_col]==BOX)) // 박스 위쪽이 벽이거나 박스이면
                {
                    do_nothing(); // 캐릭터 이동 불가능
                }
                else if(map[char_row-2][char_col]==NULL_SPACE) // 박스 앞이 비어있으면
                {
                    setElement(char_row, char_col, default_map[char_row][char_col]); // 캐릭터 있던 곳은 기본 값
                    setCharacter(char_row-1, char_col); // 캐릭터와 박스가 함께 위쪽으로 이동
                    setElement(char_row-2, char_col, BOX);
                }
                else if(map[char_row-2][char_col]==DEST) // 박스 앞이 목적지이면
                {
                    setElement(char_row, char_col, default_map[char_row][char_col]); // 캐릭터 있던 곳은 기본 값
                    setCharacter(char_row-1, char_col); // 캐릭터와 박스가 함께 위쪽으로 이동
                    setElement(char_row-2, char_col, BOX_ON_DEST); // 목적지에 박스가 들어갔음을 표시
                }
            }
            break;
        
        case 75: // <- 입력
            if(map[char_row][char_col-1]==NULL_SPACE) // 캐릭터 왼쪽이 비어있으면 캐릭터를 왼쪽으로 한칸 전진
            {
                setCharacter(char_row, char_col-1);
                setElement(char_row, char_col, default_map[char_row][char_col]);
            }
            else if(map[char_row][char_col-1]==WALL) // 캐릭터 왼쪽이 벽이면
            {
                do_nothing(); // 캐릭터 이동 불가능
            }
            else if(map[char_row][char_col-1]==BOX) // 캐릭터 왼쪽이 박스일 때
            {
                if((map[char_row][char_col-2]==WALL)||(map[char_row][char_col-2]==BOX)) // 박스 왼쪽이 벽이거나 박스이면
                {
                    do_nothing(); // 캐릭터 이동 불가능
                }
                else if(map[char_row][char_col-2]==NULL_SPACE) // 박스 앞이 비어있으면
                {
                    setElement(char_row, char_col, default_map[char_row][char_col]); // 캐릭터 있던 곳은 기본 값
                    setCharacter(char_row, char_col-1); // 캐릭터와 박스가 함께 왼쪽으로 이동
                    setElement(char_row, char_col-2, BOX);
                }
                else if(map[char_row][char_col-2]==DEST) // 박스 앞이 목적지이면
                {
                    setElement(char_row, char_col, default_map[char_row][char_col]); // 캐릭터 있던 곳은 기본 값
                    setCharacter(char_row, char_col-1); // 캐릭터와 박스가 함께 왼쪽으로 이동
                    setElement(char_row, char_col-2, BOX_ON_DEST); // 목적지에 박스가 들어갔음을 표시
                }
            }
            break;

        case 77: // -> 입력
            if(map[char_row][char_col+1]==NULL_SPACE) // 캐릭터 오른쪽이 비어있으면 캐릭터를 오른쪽으로 한칸 전진
            {
                setCharacter(char_row, char_col+1);
                setElement(char_row, char_col, default_map[char_row][char_col]);
            }
            else if(map[char_row][char_col+1]==WALL) // 캐릭터 오른쪽이 벽이면
            {
                do_nothing(); // 캐릭터 이동 불가능
            }
            else if(map[char_row][char_col+1]==BOX) // 캐릭터 오른쪽이 박스일 때
            {
                if((map[char_row][char_col+2]==WALL)||(map[char_row][char_col+2]==BOX)) // 박스 오른쪽이 벽이거나 박스이면
                {
                    do_nothing(); // 캐릭터 이동 불가능
                }
                else if(map[char_row][char_col+2]==NULL_SPACE) // 박스 앞이 비어있으면
                {
                    setElement(char_row, char_col, default_map[char_row][char_col]); // 캐릭터 있던 곳은 기본 값
                    setCharacter(char_row, char_col+1); // 캐릭터와 박스가 함께 오른쪽으로 이동
                    setElement(char_row, char_col+2, BOX);
                }
                else if(map[char_row][char_col+2]==DEST) // 박스 앞이 목적지이면
                {
                    setElement(char_row, char_col, default_map[char_row][char_col]); // 캐릭터 있던 곳은 기본 값
                    setCharacter(char_row, char_col+1); // 캐릭터와 박스가 함께 오른쪽으로 이동
                    setElement(char_row, char_col+2, BOX_ON_DEST); // 목적지에 박스가 들어갔음을 표시
                }
            }
            break;
        
        case 80: // ↓ 입력
            if(map[char_row+1][char_col]==NULL_SPACE) // 캐릭터 아래쪽이 비어있으면 캐릭터를 아래쪽으로 한칸 전진
            {
                setCharacter(char_row+1, char_col);
                setElement(char_row, char_col, default_map[char_row][char_col]);
            }
            else if(map[char_row+1][char_col]==WALL) // 캐릭터 아래쪽이 벽이면
            {
                do_nothing(); // 캐릭터 이동 불가능
            }
            else if(map[char_row+1][char_col]==BOX) // 캐릭터 아래쪽이 박스일 때
            {
                if((map[char_row+2][char_col]==WALL)||(map[char_row+2][char_col]==BOX)) // 박스 아래쪽이 벽이거나 박스이면
                {
                    do_nothing(); // 캐릭터 이동 불가능
                }
                else if(map[char_row+2][char_col]==NULL_SPACE) // 박스 앞이 비어있으면
                {
                    setElement(char_row, char_col, default_map[char_row][char_col]); // 캐릭터 있던 곳은 기본 값
                    setCharacter(char_row+1, char_col); // 캐릭터와 박스가 함께 아래쪽으로 이동
                    setElement(char_row+2, char_col, BOX);
                }
                else if(map[char_row+2][char_col]==DEST) // 박스 앞이 목적지이면
                {
                    setElement(char_row, char_col, default_map[char_row][char_col]); // 캐릭터 있던 곳은 기본 값
                    setCharacter(char_row+1, char_col); // 캐릭터와 박스가 함께 아래쪽으로 이동
                    setElement(char_row+2, char_col, BOX_ON_DEST); // 목적지에 박스가 들어갔음을 표시
                }
            }
            break;
        delete loc;
            
    }
    countBoxOnDest();
}