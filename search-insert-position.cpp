#include <iostream>
#include <vector>

class Solution 
{
public:
    int searchInsert(std::vector<int>& nums, int target) 
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (target <= nums[i]) return i;
        }
        return nums.size();
    }
};

int main()
{
    auto* nums = new std::vector<int>{1, 3, 5, 6};
    Solution solution;

    auto* index = new int(solution.searchInsert(*nums, 5));
    std::cout << *index << std::endl;

    delete index, nums;
    return 0;
}