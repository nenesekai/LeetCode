#include <iostream>
#include <string>

using namespace std;

class Solution
{

public:

    bool rotateString(string s, string goal)
    {
        int cnt = 0;

        while (goal != s)
        {
            goal += goal[0];

            goal.erase(goal.begin());

            cnt++;

            if (cnt == goal.size()) break;
        }

        return goal == s;
    }

};

int main()
{
    string s = "abcde", goal = "cdeab";

    Solution solution;

    cout << solution.rotateString(s, goal) << endl;

    return 0;
}