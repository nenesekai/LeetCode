#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:

    string convert(string s, int numRows)
    {
        if (numRows == 1) return s;

        string str = "";

        for (int i = 0; i < numRows; i++)
        {
            // str += s[i];
            
            // for (int index = i + (numRows - i - 1) * 2; index < s.size(); index += (i != numRows - 1) ? (numRows - i - 1) * 2 : 0)
            // {
            //     str += s[index];
            //     index += i * 2;
            //     if (index < s.size() && i != 0) str += s[index];
            // }

            int index = i;

            str += s[index];

            while (index < s.size())
            {
                if (i != numRows - 1)
                {
                    index += (numRows - i - 1) * 2;
                    if (index < s.size()) str += s[index];
                }
                if (i != 0)
                {
                    index += i * 2;
                    if (index < s.size()) str += s[index];
                }
            }
        }

        return str;
    }

};

int main()
{
    Solution solution;

    string s = "A";
    cout << solution.convert(s, 4) << endl;

    return 0;
}