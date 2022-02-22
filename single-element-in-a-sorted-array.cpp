#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:

    int singleNonDuplicate(vector<int>& nums)
    {

        for (int i = 0; i < nums.size(); i++)
        {
            if (i != nums.size() - 1 && nums[i] != nums[i + 1])
            {
                return nums[i];
            }
            else
            {
                i++;
            }
        }

        return nums.back();
    }

};

int main()
{
    Solution* solution = new Solution();

    vector<int> nums{1, 1, 2, 3, 3, 4, 4, 8, 8};

    cout << solution->singleNonDuplicate(nums) << endl;

    return 0;
}