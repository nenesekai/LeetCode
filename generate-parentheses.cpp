#include <iostream>
#include <vector>

using namespace std;

class Solution 
{

private:

    vector<string> results;
    int n;

public:

    vector<string> generateParenthesis(int n) 
    {
        results = {};
        this->n = n;
        differentPossibility(n, n, "");

        return results;
    }

    void differentPossibility(int left, int right, string current)
    {
        if (left != 0)
        {
            differentPossibility(left - 1, right, current + '(');
        }
        
        if (right != 0 && n - left >= n - right + 1)
        {
            if (left == 0 && right == 1)
            {
                results.push_back(current + ')');
                return;
            }
            else
            {
                differentPossibility(left, right - 1, current + ')');
            }
        }
    }

};

int main()
{
    Solution* obj = new Solution();

    vector<string> results = obj->generateParenthesis(2);

    for (vector<string>::iterator iter = results.begin(); iter < results.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}