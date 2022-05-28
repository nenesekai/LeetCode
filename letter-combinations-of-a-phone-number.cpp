#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string digits = "23";

    Solution solution;

    vector<string> combinations = solution.letterCombinations(digits);

    for (string combination : combinations)
    {
        cout << combination << " ";
    }

    cout << endl;

    return 0;
}