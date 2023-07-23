#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &lhs, vector<int> &rhs) -> bool
             { return lhs[1] < rhs[1]; });
        int endTime = intervals[0][1], kept = 1;
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] < endTime)
            {
                continue;
            }
            else
            {
                ++kept;
                endTime = intervals[i][1];
            }
        }
        return intervals.size() - kept;
    }
};

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    Solution *obj = new Solution();
    cout << obj->eraseOverlapIntervals(intervals) << endl;
    delete obj;
    return 0;
}