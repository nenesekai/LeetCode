#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {

        for (auto nums_iter = nums.begin(); nums_iter < nums.end(); nums_iter++)
        {
            *nums_iter = std::pow(*nums_iter, 2);
        }

        std::sort(nums.begin(), nums.end());

        return nums;

    }
};

int main()
{
    Solution solution;

    vector<int> nums{-4,-1,0,3,10};
    vector<int> new_nums = solution.sortedSquares(nums);

    for (auto iter = new_nums.begin()
        ; iter < new_nums.end()
        ; iter++)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    return 0;
}