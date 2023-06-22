#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int fillCups(vector<int> &amount)
    {
        return max(max(amount[0], max(amount[1], amount[2])), (amount[0] + amount[1] + amount[2] + 1) / 2);
    }
};

int main()
{
    vector<int> amount = {1, 4, 2};

    Solution* obj = new Solution();

    cout << obj->fillCups(amount) << endl;

    delete obj;

    return 0;
}