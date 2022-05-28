#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:

    vector<vector<int>> permute(vector<int>& nums)
    {
        if (nums.size() == 1) return {nums};

        vector<int>::iterator stops = nums.begin() + 1;

        vector<vector<int>> combinations = {{nums[0]}}, old_combinations;

        while (stops < nums.end())
        {
            old_combinations = combinations;

            combinations = vector<vector<int>>{};
            combinations.reserve(old_combinations.size() * (old_combinations[0].size() + 1));

            for (vector<int> old_combination : old_combinations)
            {
                for (int loc = 0; loc <= old_combination.size(); loc++)
                {
                    combinations.push_back(old_combination);
                    combinations.back().insert(combinations.back().begin() + loc, *stops);
                }
            }

            stops++;
        }

        return combinations;
    }

};

int main()
{
    vector<int> nums = {0, 1};

    Solution solution;

    auto ans = solution.permute(nums);

    for (auto grp : ans)
    {
        for (auto num : grp)
        {
            cout << num << " ";
        }

        cout << endl;
    }

    return 0;
}