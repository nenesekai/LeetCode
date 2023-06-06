#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        map<vector<int>, int> row, col;
        int result = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            if (row.find(grid[i]) == row.end())
            {
                row.insert(pair<vector<int>, int>(grid[i], 1));
            }
            else
            {
                ++row[grid[i]];
            }

            vector<int> colgrid(grid.size());
            for (int j = 0; j < grid.size(); j++)
            {
                colgrid[j] = grid[j][i];
            }
            if (col.find(colgrid) == col.end())
            {
                col.insert(pair<vector<int>, int>(colgrid, 1));
            }
            else
            {
                ++col[colgrid];
            }
        }

        for (pair<vector<int>, int> rowpair : row)
        {
            if (col.find(rowpair.first) != col.end())
            {
                result += rowpair.second * col[rowpair.first];
            }
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> grid = {{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
    Solution* obj = new Solution();
    cout << obj->equalPairs(grid) << endl;
    delete obj;
    return 0;
}