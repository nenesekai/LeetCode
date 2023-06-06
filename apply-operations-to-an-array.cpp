#include <iostream>
#include <exception>

using namespace std;

class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        vector<int>::iterator observe_pt = nums.begin(), insert_pt = nums.begin();

        while (observe_pt < nums.end() - 1)
        {
            if (*observe_pt == 0)
            {
                ++observe_pt;
            }
            else if (*observe_pt == *(observe_pt + 1))
            {
                *observe_pt *= 2;
                *(observe_pt + 1) = 0;
                *insert_pt = *observe_pt;
                ++insert_pt;
                ++observe_pt;
            }
            else if (*observe_pt != 0)
            {
                *insert_pt = *observe_pt;
                ++insert_pt;
                ++observe_pt;
            }
        }

        if (*observe_pt != 0)
        {
            *insert_pt = *observe_pt;
            ++insert_pt;
        }

        while (insert_pt < nums.end())
        {
            *insert_pt = 0;
            ++insert_pt;
        }

        return nums;
    }
};

int main()
{
    vector<int> nums{847, 847, 0, 0, 0, 399, 416, 416, 879, 879, 206, 206, 206, 272};
    Solution *obj = new Solution();
    vector<int> result = obj->applyOperations(nums);
    for (int num : result)
        cout << num << " ";
    cout << endl;
    delete obj;
    return 0;
}