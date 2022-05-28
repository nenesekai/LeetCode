#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{

public:

    bool canReorderDoubled(vector<int>& arr)
    {
        unordered_map<int, int> count;

        for (int num : arr)
        {
            count[num]++;
        }

        if (count[0] % 2 != 0) return false;

        vector<int> values;

        values.reserve(count.size());

        for (auto &[x, _] : count)
        {
            values.push_back(x);
        }

        sort(values.begin(), values.end(), [](int left, int right)
        {
            return abs(left) < abs(right);
        });

        for (int value: values)
        {
            if (count[value] > count[value * 2])
            {
                return false;
            }

            count[value * 2] -= count[value];
        }

        return true;
    }

};

int main()
{
    vector<int> arr{2,4,0,0,8,1};

    Solution solution;

    cout << solution.canReorderDoubled(arr) << endl;

    return 0;
}