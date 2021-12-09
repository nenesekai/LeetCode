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
    
}