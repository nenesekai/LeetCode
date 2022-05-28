#include <iostream>
#include <vector>

using namespace std;

class Solution 
{

public:

    int findClosestNumber(vector<int>& nums) 
    {
        int closestNumber = INT_MAX;

        for (int num : nums)
        {
            if (abs(num) < abs(closestNumber) || (abs(num) == abs(closestNumber) && num > closestNumber)) closestNumber = num;
        }

        return closestNumber;
    }

};

int main()
{   
    vector<int> nums = {-4, -2, 1, 4, 8};

    Solution* obj = new Solution();

    cout << obj->findClosestNumber(nums) << endl;

    return 0;
}