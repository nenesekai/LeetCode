#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{

public:

    int projectionArea(vector<vector<int>>& grid)
    {
        if (grid.size() == 0) return 0;

        vector<int> x_max(grid.size(), 0), y_max(grid[0].size(), 0);

        int front = 0, right = 0, top = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] > x_max[i]) x_max[i] = grid[i][j];
                if (grid[i][j] > y_max[j]) y_max[j] = grid[i][j];
                if (grid[i][j] != 0) top++;
            }
        }

        // front = accumulate(x_max.begin(), x_max.end(), 0);
        // right = accumulate(y_max.begin(), y_max.end(), 0);

        for (int i = 0; i < x_max.size(); i++)
        {
            front += x_max[i];
        }

        for (int i = 0; i < y_max.size(); i++)
        {
            right += y_max[i];
        }

        return front + right + top;
    }

};

int main()
{
    vector<vector<int>> grid = {{1, 2}, {3, 4}};

    Solution* obj = new Solution();

    cout << obj->projectionArea(grid) << endl;

    return 0;
}