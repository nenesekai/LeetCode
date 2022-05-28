#include <iostream>

using namespace std;

class Solution 
{

public:

    string removeOuterParentheses(string s) 
    {
        int parentheses_count = 0;
        bool outermost_clear = false;

        for (string::iterator iter = s.begin(); iter < s.end(); iter++)
        {
            if (*iter == '(')
            {
                if (parentheses_count == 0 && !outermost_clear)
                {
                    s.erase(iter);
                    iter--;

                    outermost_clear = true;
                }
                else
                {
                    parentheses_count++;
                }
            }
            else if (*iter == ')')
            {
                if (parentheses_count == 0 && outermost_clear)
                {
                    s.erase(iter);
                    iter--;

                    outermost_clear = false;
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
    string original_text = "(()())(())(()(()))";

    Solution *obj = new Solution();

    cout << obj->removeOuterParentheses(original_text) << endl;

    return 0;
}
