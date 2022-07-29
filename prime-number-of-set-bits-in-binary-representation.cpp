#include <iostream>
#include <bitset>
#include <string>

using namespace std;

class Solution
{

public:

    int to_binary(int num)
    {
        int rt = 0;

        while (num != 0)
        {
            rt += num % 2;
            num /= 2;
        }

        return rt;
    }

    int is_prime(int num)
    {
        if (num == 0 || num == 1) return 0;

        for (int i = 2; i < num; i++) 
        {
            if (num % i == 0) return 0;
        }

        return 1;
    }

    int countPrimeSetBits(int left, int right)
    {
        int rt = 0, bit_cnt = 0;

        for (int num = left, bit_cnt = to_binary(num); num <= right; num++, bit_cnt = to_binary(num))
        {
            rt += is_prime(bit_cnt);
        }

        return rt;
    }

};

int main()
{
    Solution solution;

    cout << solution.countPrimeSetBits(6, 10);

    return 0;
}

