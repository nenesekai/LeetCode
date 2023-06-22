#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size();

        while (start < end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else if (nums[mid] > target)
            {
                end = mid;
            }
        }

        return -1;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 3, 5, 9, 12};

    Solution* obj = new Solution();

    cout << obj->search(nums, 9) << endl;

    delete obj;

    return 0;
}