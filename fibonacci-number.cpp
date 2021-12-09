#include <iostream>
#include <vector>

using namespace std;

// class Solution 
// {

// public:

//     int fib(int n) 
//     {
//         if (n <= 1) return n;

//         return fib(n - 1) + fib(n - 2);
//     }

// };

class Solution 
{

public:

    int fib(int n) 
    {
        if (n == 0) return 0;
        if (n == 1) return 1;

        vector<int> fib{0, 1};

        for (int i = 2; i <= n; i++)
        {
            fib[i] = fib[i - 1] + fib[i - 2];
        }

        return fib[n];
    }

};

int main()
{
    return 0;
}