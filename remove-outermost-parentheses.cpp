#include <iostream>

using namespace std;

class Solution 
{

public:

    string removeOuterParentheses(string s) 
    {
        int parentheses_count = 0;

        for (string::iterator iter = s.begin(); iter < s.end(); iter++)
        {
            if (*iter == '(')
            {
                if (parentheses_count == 0)
                {
                    s.erase(iter);
                    iter--;
                }
                else
                {
                    parentheses_count++;
                }
            }
            else if (*iter == ')')
            {
                if (parentheses_count == 0)
                {
                    s.erase(iter);
                    iter--;
                }
                else
                {
                    parentheses_count--;
                }
            }
        }

        return s;
    }

};

int main()
{
    string original_text = "(()())(())";

    Solution* obj = new Solution;

    string result = obj->removeOuterParentheses(original_text);

    cout << result << endl;

    return 0;
}