#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int unequalTriplets(vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            for (int j = i + 1; j < nums.size() - 1; ++j)
            {
                if (nums[i] == nums[j]) continue;
                for (int z = j + 1; z < nums.size(); ++z)
                {
                    if (nums[i] != nums[z] && nums[j] != nums[z])
                    {
                        ++count;
                    }
                }
            }
        }
        return count;
    }
};

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    Solution *obj = new Solution();
    cout << obj->unequalTriplets(nums) << endl;
    delete obj;
    return 0;
}