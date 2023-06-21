#include <iostream>

using namespace std;

class Solution
{
public:
    static bool match(string longstr, string shortstr)
    {
        if (longstr.size() % shortstr.size() != 0) return false;
        for (int i = 0; i < longstr.size(); i++)
        {
            if (longstr[i] != shortstr[i % shortstr.size()]) return false;
        }
        return true;
    }

    string gcdOfStrings(string str1, string str2)
    {
        if (str1 < str2) swap(str1, str2);
        for (int i = str2.size(); i > 0; --i)
        {
            string str = str2.substr(0, i);
            if (match(str1, str) && match(str2, str)) return str;
        }

        return "";
    }
};

int main()
{
    return 0;
}