#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{

public:

    unordered_map<int, vector<int>> index_map;

    Solution(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0 || nums[i] != nums[i-1])
            {
                
            }
        }
    }

    int pick(int target) 
    {

    }

};

int main()
{
    vector<int> nums = {1, 2, 3, 3, 3};

    Solution* obj = new Solution(nums);

    cout << obj->pick(3) << endl;

    cout << obj->pick(1) << endl;

    return 0;
}