#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:

    vector<int> selfDividingNumbers(int left, int right)
    {
        auto is_self_dividing = [](int num)
        {
            int original_num = num, digit = 0;
            while (num != 0)
            {
                digit = num % 10;
                num /= 10;

                if (digit == 0 || original_num % digit != 0) return false;
            }

            return true;
        };

        vector<int> rt;

        for (int num = left; num <= right; num++)
        {
            if (is_self_dividing(num)) rt.push_back(num);
        }

        return rt;
    }

};

int main()
{
    int left = 1, right = 22;

    Solution solution;

    vector<int> nums = solution.selfDividingNumbers(left, right);

    for (int num : nums)
    {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}