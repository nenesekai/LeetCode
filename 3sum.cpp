#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{

public: 

    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> rt;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0) return rt;

            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1, z = nums.size() - 1, total = 0;

            while (j < z)
            {
                total = nums[i] + nums[j] + nums[z];

                if (total == 0)
                {
                    rt.push_back({nums[i], nums[j], nums[z]});

                    do
                    {
                        j++;
                    } while (j < z && nums[j] == nums[j - 1]);

                    do
                    {
                        z--;
                    } while (j < z && nums[z] == nums[z + 1]);
                }
                else if (total < 0)
                {
                    do
                    {
                        j++;
                    } while (j < z && nums[j] == nums[j - 1]);
                }
                else
                {
                    do
                    {
                        z--;
                    } while (j < z && nums[z] == nums[z + 1]);
                }
            }
        }

        return rt;
    }

};

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    Solution solution;

    auto ans = solution.threeSum(nums);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}