#include <iostream>

using namespace std;

class Solution 
{

public:

    int climbStairs(int n) 
    {
        int a = 1, b = 2, c = a + b;

        if (n == a) return a;
        if (n == b) return b;
        if (n == c) return c;

        int count = 4;

        while (true)
        {
            a = b;
            b = c;
            c = a + b;

            if (count == n) return c;

            count++;
        }

        return 0;
    }

};

int main()
{
    Solution solution;

    cout << solution.climbStairs(2) << endl;

    return 0;
}