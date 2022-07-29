#include <iostream>

using namespace std;

class Solution
{

public:

    double myPow(double x, int n)
    {
        if (n == 0) return 1;

        if (x == 1) return 1;
        if (x == -1) return n % 2 == 0 ? 1 : -1;

        bool neg = n < 0;

        double rt = x;

        unsigned long long me = 1;

        while (me < abs(n))
        {
            if (me * 2 <= abs(n))
            {
                rt *= rt;
                me *= 2;
            }
            else
            {
                rt *= x;
                me++;
            }
        }

        return neg ? 1 / rt : rt;
    }

};

int main()
{
    double x = 2;
    int n = 10;

    Solution solution;

    cout << solution.myPow(x, n) << endl;

    return 0;
}