#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Solution 
{

public:

    int findNthDigit(int n) 
    {
        int digit = 0, starting;

        for (int digit_amount = 9
            ; digit < 31
            ; digit++, digit_amount += 9 * pow(10, digit) * (digit + 1))
        {
            if (n <= digit_amount) break;
            starting = digit_amount;
        }
        
        if (digit == 0) return n;

        n -= starting;
        
        if (n % (digit + 1) == 0)
        {
            return (int) ((9 * pow(10, digit - 1)) + (n / (digit + 1))) % 10;
        }
        else
        {
            for (int num = (((9 * pow(10, digit - 1)) + (n / (digit + 1)) + 1)) / 10, count = digit; count == n % (digit + 1); num /= 10, count--)
            {
                return num % 10;
            }
        }
    }

};

int main()
{
    Solution solution;

    for (int i = 900; i < 1100; i++) cout << solution.findNthDigit(1000);

    return 0;
}