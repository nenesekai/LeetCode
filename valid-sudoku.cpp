#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool vert[10], hori[10];
        for (int i = 0; i < 8; ++i)
        {
            for (int i = 0; i < 9; ++i) 
            {
                vert[i] = false;
                hori[i] = false;
            }
            for (int j = 0; j < 8; ++j)
            {
                if (board[i][j] != '.')
                {
                    if (vert[board[i][j] - '0'])
                    {
                        return false;
                    }
                    else
                    {
                        vert[board[i][j] - '0'] = true;
                    }
                }
                if (board[j][i] != '.')
                {
                    if (hori[board[j][i] - '0'])
                    {
                        return false;
                    }
                    else
                    {
                        hori[board[j][i] - '0'] = true;
                    }
                }
            }
        }
    }
};

int main()
{
    return 0;
}