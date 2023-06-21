#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> pondSizes(vector<vector<int>> &land)
    {
        vector<int> results;
        for (int i = 0; i < land.size(); ++i)
        {
            for (int j = 0; j < land[i].size(); ++j)
            {
                if (land[i][j] == 0)
                {
                    results.push_back(calculateArea(land, i, j));
                }
            }
        }
        sort(results.begin(), results.end());
        return results;
    }

    int calculateArea(vector<vector<int>> &land, int x, int y)
    {
        int area = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        while (!q.empty())
        {
            int i = q.front().first, j = q.front().second;
            q.pop();
            if (i < 0 || i >= land.size() || j < 0 || j >= land[i].size()) continue;
            if (land[i][j] == 0)
            {
                ++area;
                q.push(make_pair(i+1, j+1));
                q.push(make_pair(i+1, j));
                q.push(make_pair(i+1, j-1));
                q.push(make_pair(i, j+1));
                q.push(make_pair(i, j-1));
                q.push(make_pair(i-1, j+1));
                q.push(make_pair(i-1, j));
                q.push(make_pair(i-1, j-1));
                land[i][j] = 1;
            }
        }
        return area;
    }
};

int main()
{
    vector<vector<int>> land = {
        { 0, 2, 1, 0 },
        { 0, 1, 0, 1 },
        { 1, 1, 0, 1 },
        { 0, 1, 0, 1 }
    };
    Solution *obj = new Solution();
    vector<int> results = obj->pondSizes(land);
    for (int result : results)
    {
        cout << result << " ";
    }
    cout << endl;
    delete obj;
    return 0;
}