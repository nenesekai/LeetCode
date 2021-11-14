#include <iostream>
#include <math.h>

class Solution 
{
public:
    int bulbSwitch(int n) 
    {
        return sqrt(n);
    }
};

int main()
{
    Solution solution;
    std::cout << solution.bulbSwitch(3) << std::endl;
    return 0;
}