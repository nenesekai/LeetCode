#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{
public:
    int distinctAverages(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int start = 0, end = nums.size() - 1, avg_count = 0;
        set<double> avgs;

        while (start <= end)
        {
            double avg = (nums[start] + nums[end]) / 2.0; // cal avg value
            avgs.insert(avg);
            ++start;
            --end;
        }   

        return avgs.size();
    }
};

int main()
{
    vector<int> nums {1, 100};

    Solution* obj = new Solution();

    cout << obj->distinctAverages(nums) << endl;

    delete obj;

    return 0;
}