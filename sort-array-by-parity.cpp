#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:

    vector<int> sortArrayByParity(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                nums.insert(nums.begin(), nums[i]);
                nums.erase(nums.begin() + 1 + i);
            }
        }

        return nums;
    }

};

int main()
{
    vector<int> nums = {3, 1, 2, 4};

    Solution* obj = new Solution();

    vector<int> result = obj->sortArrayByParity(nums);

    for (int num : result) cout << num << " ";

    cout << endl;

    return 0;
}