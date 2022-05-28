#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:

    vector<int> missingRolls(vector<int>& rolls, int mean, int n)
    {
        int total = 0, missing_total = 0;

        for (int val : rolls)
        {
            total += val;
        }

        missing_total = (mean * (n + rolls.size())) - total;

        if (missing_total > n * 6 || missing_total < n) return vector<int>{}; // impossible situation

        vector<int> missing(n, missing_total / n);

        if (missing[0] + missing_total % n > 6)
        {
            auto iter = missing.begin();

            missing_total %= n;

            while (missing_total > 0)
            {
                (*iter)++;
                missing_total--;

                iter++;
            }
        }
        else
        {
            missing[0] += missing_total % n;
        }

        return missing;
    }

};

int main()
{
    vector<int> rolls{4,5,6,2,3,6,5,4,6,4,5,1,6,3,1,4,5,5,3,2,3,5,3,2,1,5,4,3,5,1,5};
    int mean = 4, n = 40;

    Solution solution;

    vector<int> missing = solution.missingRolls(rolls, mean, n);

    for (int val : missing)
    {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}