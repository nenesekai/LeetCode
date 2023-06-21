#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numTimesAllBlue(vector<int> &flips)
    {
        if (flips.size() == 0) return 0;
        if (flips.size() == 1) return 1;

        vector<bool> allZeros(flips.size(), true), allOnes(flips.size(), false);
        int count;
        for (int i = 0; i < flips.size(); ++i)
        {
            
        }
    }
};

int main()
{
    return 0;
}