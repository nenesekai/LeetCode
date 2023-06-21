#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    void print(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }

    int closedIsland(vector<vector<int>> &grid)
    {
        int count = 0;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 0 && bfsRecursive(grid, i, j)) count++;
            }
        }

        return count;
    }

    bool bfsRecursive(vector<vector<int>> &grid, int x, int y)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size())
        {
            return false;
        }
        if (grid[x][y] == 1)
        {
            return true;
        }
        grid[x][y] = 1;
        bool result = true;
        result &= bfsRecursive(grid, x+1, y);
        result &= bfsRecursive(grid, x-1, y);
        result &= bfsRecursive(grid, x, y+1);
        result &= bfsRecursive(grid, x, y-1);
        return result;
    }

    bool bfs(vector<vector<int>> &grid, int x, int y)
    {
        bool isIsland = true;
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        while (!q.empty())
        {
            int i = q.front().first, j = q.front().second;
            q.pop();
            if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size())
            {
                isIsland = false;
                continue;
            }
            if (grid[i][j] == 1)
            {
                continue;
            }
            grid[i][j] = 1;
            q.push(make_pair(i+1, j));
            q.push(make_pair(i-1, j));
            q.push(make_pair(i, j+1));
            q.push(make_pair(i, j-1));
        }
        return isIsland;
    }
};

int main()
{
    vector<vector<int>> grid = {{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};
    Solution *obj = new Solution();
    cout << obj->closedIsland(grid) << endl;
    delete obj;
    return 0;
}