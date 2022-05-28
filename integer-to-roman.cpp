#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution
{

public:

    string intToRoman(int num)
    {
        int digit;

        string rt;

        vector<pair<string, string>> symbol{pair<string, string>("I", "V"), pair<string, string>("X", "L"), pair<string, string>("C", "D"), pair<string, string>("M", "MMMMM")};

        for (int pos = 3; pos >= 0; pos--)
        {
            digit = num / pow(10, pos);
            num -= digit * pow(10, pos);

            if (0 < digit && digit <= 3)
            {
                for (int i = 0; i < digit; i++) rt += symbol[pos].first;
            }

            if (digit == 4) rt += symbol[pos].first + symbol[pos].second;

            if (5 <= digit && digit <= 8)
            {
                rt += symbol[pos].second;

                for (int i = digit - 5; i > 0; i--)
                {
                    rt += symbol[pos].first;
                }
            }

            if (digit == 9) rt += symbol[pos].first + symbol[pos + 1].first;
        }

        return rt;
    }

};

int main()
{
    Solution solution;

    cout << solution.intToRoman(1994);

    return 0;
}