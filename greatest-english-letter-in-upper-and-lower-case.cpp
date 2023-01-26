#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string greatestLetter(string str)
    {
        vector<bool> lower(26, false);
        vector<bool> upper(26, false);

        for (int idx = 0; idx < str.size(); idx++)
        {
            if (str[idx] >= 'a' && str[idx] <= 'z')
            {
                lower[str[idx] - 'a'] = true;
            }
            else if (str[idx] >= 'A' && str[idx] <= 'Z')
            {
                upper[str[idx] - 'A'] = true;
            }
        }

        string ret = "";

        for (int idx = 25; idx >= 0; idx--)
        {
            if (lower[idx] && upper[idx]) 
            {
                ret = 'A' + idx;
                break;
            }
        }

        return ret;
    }
};

int main()
{
    string str = "lEeTcOdE";

    Solution* obj = new Solution();

    cout << obj->greatestLetter(str) << endl;

    delete obj;

    return 0;
}
