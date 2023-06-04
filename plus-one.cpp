#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int ptr = digits.size() - 1;

        for (;;)
        {
            ++digits[ptr];
            if (digits[ptr] == 10)
            {
                digits[ptr] = 0;
                if (ptr == 0)
                {
                    digits.push_back(digits[digits.size() - 1]);
                    for (int i = digits.size() - 2; i > 0; i--)
                    {
                        digits[i] = digits[i - 1];
                    }
                    digits[0] = 1;
                    break;
                }
                else
                {
                    --ptr;
                    continue;
                }
            }
            else
            {
                break;
            }
        }

        return digits;
    }
};

int main()
{
    vector<int> test_data{1, 2, 3};

    Solution *instance = new Solution();

    vector<int> result = instance->plusOne(test_data);

    for (int num : result) cout << num;
    cout << endl;

    delete instance;

    return 0;
}