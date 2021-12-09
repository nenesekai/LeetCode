#include <iostream>
#include <vector>

class Solution 
{
public:
    void rotate(std::vector<int>& nums, int k) 
    {
        k %= nums.size();
        
        int index = 0;
        std::vector<int> alt_nums = nums;

        for (index = 0; index < k; index++)
        {
            nums[index] = alt_nums[alt_nums.size() - k + index];
        }

        for (; index < nums.size(); index++)
        {
            nums[index] = alt_nums[index - k];
        }
    }
};

int main()
{
    Solution solution;
    std::vector<int> nums{-1, -100, 3, 99};

    solution.rotate(nums, 2);

    for (auto nums_iter = nums.begin()
        ; nums_iter < nums.end()
        ; nums_iter++)
    {
        std::cout << *nums_iter << " ";
    }
    std::cout << std::endl;

    return 0;
}