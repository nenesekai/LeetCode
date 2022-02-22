#include <iostream>

using namespace std;

class Solution
{

public:

    int myAtoi(string s)
    {
        long long num = 0, ptr = 0;
        bool positive = true;

        // step one
        while (s[ptr] == ' ')
        {
            ptr++;
        }

        if (ptr >= s.size()) return 0;

        // step two
        if (s[ptr] == '+' || s[ptr] == '-')
        {
            positive = (s[ptr] == '-') ? false : true;
            ptr++;
        }

        while (ptr < s.size())
        {
            if (s[ptr] >= '0' && s[ptr] <= '9')
            {
                num *= 10;
                num += (int) (s[ptr] - '0');

                if (positive && num > INT_MAX) 
                {
                    num = INT_MAX;
                    break;
                }
                if (!positive && -1 * num < INT_MIN) 
                {
                    num = INT_MIN;
                    break;
                }
            }
            else
            {
                break;
            }
            ptr++;
        }

        return num * (positive ? 1 : -1);
    }

};

int main()
{
    Solution solution;
    string s = "-42";

    cout << solution.myAtoi(s) << endl;

    return 0;
}