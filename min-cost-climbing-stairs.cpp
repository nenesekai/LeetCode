#include <iostream>
#include <vector>

using namespace std;

class Solution 
{

public:

    int minCostClimbingStairs(vector<int>& cost) 
    {
        for (auto cost_iter = cost.end() - 3; cost_iter >= cost.begin(); cost_iter--)
        {
            *cost_iter += min(*(cost_iter + 1), *(cost_iter + 2));
        }

        return min(cost[0], cost[1]);
    }

};



int main()
{
    Solution solution;

    vector<int> stairs{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    
    cout << solution.minCostClimbingStairs(stairs) << endl;

    return 0;
}