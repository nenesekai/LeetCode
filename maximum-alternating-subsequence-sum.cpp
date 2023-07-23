#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    long long maxAlternatingSum(vector<int> &nums)
    {
        if (nums.size() == 1) return nums[0];
        long long dp_prev0 = nums[0], dp_prev1 = 0, dp0, dp1;

        for (int i = 1; i < nums.size(); ++i)
        {
            dp0 = max(dp_prev0, dp_prev1 + nums[i]);
            dp1 = max(dp_prev1, dp_prev0 - nums[i]);
            dp_prev0 = dp0;
            dp_prev1 = dp1;
        }

        return dp0;
    }
};

int main()
{
    return 0;
}