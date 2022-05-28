#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{

public:

    int divide(long long dividend, long long divisor)
    {
        bool pos = true;

        if (dividend < 0)
        {
            dividend *= -1;
            pos = !pos;
        }

        if (divisor < 0)
        {
            divisor *= -1;
            pos = !pos;
        }

        unsigned long long result = 1;

        if (dividend < divisor) return 0;

        if (dividend == divisor) return pos ? 1 : -1;

        if (divisor == 1)
        {
            result = divisor * (pos ? 1 : -1);

            return (result > INT_MAX) ? INT_MAX : result;
        }

        for (result = 1; !(result * divisor <= dividend && (result + 1) * divisor > dividend); result++)
        {
            int hyp1 = std::pow(result * divisor, 2);

            if (hyp1 <= dividend)
            {
                result *= result * divisor;

                result--;

                continue;
            }

            int hyp2 = std::pow(divisor, 2) * result;

            if (hyp2 <= dividend)
            {
                result *= divisor;

                result--;

                continue;
            }

            int hyp3 = std::pow(result, 2) * divisor;

            if (hyp3 <= dividend && result != 1)
            {
                result *= result;

                result--;

                continue;
            }
        }

        return (result > INT_MAX) ? INT_MAX : (result * (pos ? 1 : -1));
    }

};

int main()
{
    int dividend = 7, divisor = 3;

    Solution solution;

    cout << solution.divide(dividend, divisor) << endl;

    return 0;
}