#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() < 3) return vector<vector<int>>();
        vector<vector<int>> results;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            if ((i > 0) && (nums[i] == nums[i - 1])) continue;
            for (int j = i + 1; j < nums.size() - 1; ++j)
            {
                if ((j > i + 1) && (nums[j] == nums[j - 1])) continue;
                int start = j + 1;
                int end = nums.size();
                while (start < end)
                {
                    int mid = start + (end - start) / 2, sum = nums[i] + nums[j] + nums[mid];
                    if (sum == 0)
                    {
                        results.push_back(vector<int>{nums[i], nums[j], nums[mid]});
                        break;
                    }
                    else if (sum < 0)
                    {
                        start = mid + 1;
                    }
                    else if (sum > 0)
                    {
                        end = mid;
                    }
                }
            }
        }
        return results;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution *obj = new Solution();
    vector<vector<int>> results = obj->threeSum(nums);
    for (vector<int> result : results)
    {
        for (int resul : result)
        {
            cout << resul << " ";
        }
        cout << endl;
    }
    delete obj;
    return 0;
}