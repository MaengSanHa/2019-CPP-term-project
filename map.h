#include <vector>
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

// interface for push box map

const int NULL_SPACE=0, WALL=1, BOX=2, DEST=3, OUTSIDE=4, CHARACTER = 5, BOX_ON_DEST=6;

class Map
{
    public:
        vector<vector<int>> vec;

        // Constructor
        Map(vector<vector<int>> vector);

        void setElement(int x, int y, int input);
};