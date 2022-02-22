#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:

    vector<vector<int>> dirs{{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};

    double knightProbability(int n, int k, int row, int column)
    {
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n)));

        for (int step = 0; step <= k; step++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (step == 0)
                    {
                        dp[step][i][j] = 1;
                    }
                    else
                    {    
                        for (vector<int> dir: dirs)
                        {
                            int new_i = i + dir[0], new_j = j + dir[1];

                            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n)
                            {
                                dp[step][i][j] += dp[step - 1][new_i][new_j] / 8;
                            }
                        }
                    }
                }
            }
        }

        return dp[k][row][column];
    }
    
};

int main()
{
    Solution solution;

    cout << solution.knightProbability(3, 2, 0, 0) << endl;

    return 0;
}