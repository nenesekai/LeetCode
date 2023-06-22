#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> maxLocal(n-2, vector<int>(n-2));

        for (int i = 0; i < n - 2; ++i)
        {
            for (int j = 0; j < n - 2; ++j)
            {
                int max = grid[i][j];
                for (int i_offset = 0; i_offset < 3; ++i_offset)
                {
                    for (int j_offset = 0; j_offset < 3; ++j_offset)
                    {
                        max = std::max(max, grid[i + i_offset][j + j_offset]);
                    }
                }

                maxLocal[i][j] = max;
            }
        }

        return maxLocal;
    }
};

int main()
{
    return 0;
}