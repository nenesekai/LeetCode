#include <iostream>
#include <vector>

using namespace std;

class Solution 
{

public:

    int _max(int a, int b, int c)
    {
        if (a >= b && a >= c) return a;
        if (b >= a && b >= c) return b;
        return c;
    }

    int rob(vector<int>& nums)
    {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        if (nums.size() == 3) return _max(nums[0], nums[1], nums[2]);

        vector<int> dp1(nums.size()), dp2(nums.size());
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        dp2[0] = nums[1];
        dp2[1] = max(nums[1], nums[2]);

        for (int i = 2; i < nums.size() - 1; i++)
        {
            dp1[i] = max(dp1[i-1], dp1[i-2] + nums[i]);
            dp2[i] = max(dp2[i-1], dp2[i-2] + nums[i+1]);
        }

        return max(dp1.at(dp1.size() - 2), dp2.at(dp2.size() - 2));
    }

};

int main()
{
    Solution solution;
    vector<int> nums{1, 2, 3, 1};

    cout << solution.rob(nums) << endl;

    return 0;
}