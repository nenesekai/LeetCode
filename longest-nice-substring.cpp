#include <iostream>
#include <map>

using namespace std;

class Solution
{

public:

    string longestNiceSubstring(string s)
    {
        map<char, bool> count;
        string max_str = "", new_str = "";

        for (int i = 0; i < s.length(); i++)
        {
            count[s[i]] = true;
        }

        char low_cap = 'a';
        char cap = 'A';

        for (; low_cap <= 'z'; low_cap++, cap++)
        {
            if (count[low_cap] && !count[cap]) count[low_cap] = false;
            else if (!count[low_cap] && count[cap]) count[cap] = false;
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (count[s[i]]) 
            {
                new_str += s[i];
            }
            else
            {
                if (new_str.length() > max_str.length()) max_str = new_str;
                new_str = "";
            }
        }

        if (new_str.length() > max_str.length()) max_str = new_str;

        return max_str;
    }

};

int main()
{
    Solution solution;

    cout << solution.longestNiceSubstring("YazaAay") << endl;

    return 0;
}