#include <iostream>
#include <vector>

class Solution 
{
public:
    void moveZeroes(std::vector<int>& nums) 
    {
        auto nums_zeroless_iter = nums.begin();

        for (auto nums_iter = nums.begin(); nums_iter < nums.end(); nums_iter++)
        {
            if (*nums_iter != 0)
            {
                *nums_zeroless_iter = *nums_iter;
                nums_zeroless_iter++;
            }
        }

        for (; nums_zeroless_iter < nums.end(); nums_zeroless_iter++)
            *nums_zeroless_iter = 0;   
    }
};

int main()
{
    return 0;
}