#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:

    int deleteAndEarn(vector<int>& nums)
    {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        
        int max_val = INT_MIN;

        for (int val : nums)
        {
            if (val > max_val) max_val = val;
        }

        vector<int> count(max_val + 1), dp(max_val + 1);

        for (int val : nums)
        {
            count[val] ++;
        }

        dp[0] = count[0];
        dp[1] = max(count[0], count[1]);

        for (int i = 2; i <= max_val; i++)
        {
            dp[i] = max(dp[i - 2] + count[i] * i, dp[i - 1]);
        }

        return dp[max_val];
    }

};

int main()
{
    Solution solution;

    vector<int> nums{ 3, 4, 2 };

    cout << solution.deleteAndEarn(nums) << endl;

    return 0;
}