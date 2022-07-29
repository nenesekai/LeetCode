#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:

    bool isMatch(string s, string p)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1));

        dp[0][0] = 1; // if nothing is in s and p, consider match

        auto match = [&](int i, int j)
        {
            if (i == 0) return false;

            if (p[j - 1] == '.') return true;

            return s[i - 1] == p[j - 1];
        };

        for (int i = 0; i <= s.size(); i++)
        {
            for (int j = 1; j <= p.size(); j++)
            {
                if (p[j - 1] == '*')
                {
                    dp[i][j] |= dp[i][j - 2]; // delete the last two including chr and *

                    if (match(i, j - 1))
                    {
                        dp[i][j] |= dp[i - 1][j];
                    }
                }
                else
                {
                    if (match(i, j)) dp[i][j] |= dp[i - 1][j - 1];
                }
            }
        }

        return dp[s.size()][p.size()];
    }

};

int main()
{
    string s = "aab", p = "c*a*b";

    Solution solution;

    cout << solution.isMatch(s, p) << endl;

    return 0;
}