#include <iostream>
#include <vector>

#define mid(start, end) (end - start) / 2 + start

class Solution 
{
public:
    int search(std::vector<int>& nums, int target) 
    {
        int start = 0, end = nums.size() - 1;
        for(;;)
        {
            if (start == end) 
            {
                return nums[start] == target ? start : -1;
            }
            else if (start + 1 == end)
            {
                if (nums[start] == target) return start;
                if (nums[end] == target) return end;
                return -1;
            }
            else if (nums[mid(start, end)] == target)
            {
                return mid(start, end);
            }
            else if (nums[mid(start, end)] < target)
            {
                start = mid(start, end) + 1;
            }
            else if (nums[mid(start, end)] > target)
            {
                end = mid(start, end) - 1;
            }
        }

        return -1; // unreachable
    }
};

int main()
{
    Solution solution;
    auto* nums = new std::vector<int>{-1, 0, 3, 5, 9, 12};
    int* target = new int(2);

    std::cout << solution.search(*nums, *target) << std::endl;

    delete nums, target;
    return 0;
}