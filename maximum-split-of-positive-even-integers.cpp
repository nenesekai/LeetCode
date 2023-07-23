#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<long long> maximumEvenSplit(long long finalSum)
    {
        vector<long long> res;
        if (finalSum % 2 != 0) return res;
        for (long long i = 2; i <= finalSum; i += 2)
        {
            res.push_back(i);
            finalSum -= i;
        }
        res.back() += finalSum;
        return res;
    }
};

int main()
{
    return 0;
}