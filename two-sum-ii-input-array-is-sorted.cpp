#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {

        for (auto i = nums.begin(); i < nums.end() - 1; i++)
            if ((*i + *(i + 1)) <= target && (*i + *(nums.end() - 1)) >= target)
            {
                auto start = i + 1, end = nums.end() - 1, current = (end - start) / 2 + start;
                while (*i + *current != target && start + 1 < end)
                {
                    int sum = *i + *current;
                    if (sum > target)
                        end = current;
                    else if (sum < target)
                        start = current;

                    current = (end - start) / 2 + start;
                }
                if (*i + *current == target)
                    return std::vector<int>{
                        (int)(i - nums.begin() + 1), (int)(current - nums.begin() + 1)};
                if (*i + *start == target)
                    return std::vector<int>{
                        (int)(i - nums.begin() + 1), (int)(start - nums.begin() + 1)};
                if (*i + *end == target)
                    return std::vector<int>{
                        (int)(i - nums.begin() + 1), (int)(end - nums.begin() + 1)};
            }

        return std::vector<int>{-1, -1};
    }
};

int main()
{
    Solution solution;
    std::vector<int> nums{3, 24, 50, 79, 88, 150, 345};

    std::vector<int> ans = solution.twoSum(nums, 200);

    for (auto iter = ans.begin(); iter < ans.end(); iter++)
        std::cout << *iter << " ";
    std::cout << std::endl;

    return 0;
}