#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution 
{

public:

    int superPow(int a, vector<int>& b) 
    {
        unsigned long long real_b;

        for (auto b_iter = b.begin(); b_iter < b.end(); b_iter++)
        {
            real_b *= 10;
            real_b += *b_iter;
        }

        return (int) pow(a, real_b) % 1337;
    }   

};

int main()
{

    return 0;
}