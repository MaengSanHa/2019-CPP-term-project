// 0 represents null space
// 1 represents wall
// 2 represents box
// 3 represents destination
// 4 represents outside
// 5 represents character
// 6 represents box on destination

// interface for push box game map

typedef unsigned int uint;

template<uint row, uint col>
class map
{
    public:
        uint mat[row][col];
        const int NULL_SPACE=0, WALL=1, BOX=2, DEST=3, OUTSIDE=4, CHARACTER = 5, BOX_ON_DEST=6;
        // default constructor
        map()
        {
            for(int i=0; i<row; i++)
            {
                for(int j=0; j<col; j++)
                {
                    this->mat[i][j] = 0;
                }
            }
        }
        void setValue(int row, int col, int val)
        {
            this->mat[row][col] = val;
        }
};