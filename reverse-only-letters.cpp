#include <iostream>

using namespace std;

class Solution
{

public:

    string reverseOnlyLetters(string s)
    {
        if (s.size() < 2) return s;

        int ptr_left = 0, ptr_right = s.size() - 1;

        string new_s = "";

        while (ptr_left < s.size())
        {
            if ((s[ptr_left] >= 'a' && s[ptr_left] <= 'z') || (s[ptr_left] >= 'A' && s[ptr_left] <= 'Z'))
            {
                while (!((s[ptr_right] >= 'a' && s[ptr_right] <= 'z') || (s[ptr_right] >= 'A' && s[ptr_right] <= 'Z')) && ptr_right >= 0)
                {
                    ptr_right--;
                }

                new_s += s[ptr_right];
                
                ptr_right--;
            }
            else
            {
                new_s += s[ptr_left];
            }

            ptr_left++;
        }

        return new_s;
    }

};

int main()
{
    string str = "a-bC-dEf-ghIj";

    Solution solution;

    cout << solution.reverseOnlyLetters(str) << endl;

    return 0;
}