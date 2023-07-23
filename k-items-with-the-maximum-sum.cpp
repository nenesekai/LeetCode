#include <iostream>

using namespace std;

class Solution
{
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
    {
        if (numOnes >= k) return k;
        else if (numOnes + numZeros >= k) return numOnes;
        else return 2 * numOnes - k + numZeros;
    }
};

int main()
{
    return 0;
}