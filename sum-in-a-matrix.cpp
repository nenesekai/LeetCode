#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int matrixSum(vector<vector<int>> &nums)
    {
        int score = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sort(nums[i].begin(), nums[i].end());
        }
        for (int i = 0; i < nums[0].size(); ++i)
        {
            int max = nums[0][i];
            for (int j = 1; j < nums.size(); ++j)
            {
                if (nums[j][i] > max) max = nums[j][i];
            }
            score += max;
        }
        return score;
    }
};

int main()
{
    vector<vector<int>> nums = {{7,2,1},{6,4,2},{6,5,3},{3,2,1}};
    Solution *obj = new Solution;
    cout << obj->matrixSum(nums) << endl;
    delete obj;
    return 0;
}