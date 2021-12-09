#include <iostream>
#include <string>
#include <vector>
#include <map>

class Solution
{
public:
    std::string originalDigits(std::string s)
    {
        std::map<char, int> chr;
        std::map<int, int> num;
        std::string result = "";

        for (int index = 0; index < s.size(); index++)
        {
            chr[s[index]]++;
            if (chr['z'] > 0 && chr['e'] > 0 && chr['r'] > 0 && chr['o'] > 0)
            {
                num[0]++;
                chr['z']--;
                chr['e']--;
                chr['r']--;
                chr['o']--;
            } // zero
            if (chr['o'] > 0 && chr['n'] > 0 && chr['e'] > 0)
            {
                num[1]++;
                chr['o']--;
                chr['n']--;
                chr['e']--;
            } // one
            if (chr['t'] > 0 && chr['w'] > 0 && chr['o'] > 0)
            {
                num[2]++;
                chr['t']--;
                chr['w']--;
                chr['o']--;
            } // two
            if (chr['t'] > 0 && chr['h'] > 0 && chr['r'] > 0 && chr['e'] > 1)
            {
                num[3]++;
                chr['t']--;
                chr['h']--;
                chr['r']--;
                chr['e'] -= 2;
            } // three
            if (chr['f'] > 0 && chr['o'] > 0 && chr['u'] > 0 && chr['r'] > 0)
            {
                num[4]++;
                chr['f']--;
                chr['o']--;
                chr['u']--;
                chr['r']--;
            } // four
            if (chr['f'] > 0 && chr['i'] > 0 && chr['v'] > 0 && chr['e'] > 0)
            {
                num[5]++;
                chr['f']--;
                chr['i']--;
                chr['v']--;
                chr['e']--;
            } // five
            if (chr['s'] > 0 && chr['i'] > 0 && chr['x'] > 0)
            {
                num[6]++;
                chr['s']--;
                chr['i']--;
                chr['x']--;
            } // six
            if (chr['s'] > 0 && chr['e'] > 1 && chr['v'] > 0 && chr['n'] > 0)
            {
                num[7]++;
                chr['s']--;
                chr['e'] -= 2;
                chr['v']--;
                chr['n']--;
            } // seven
            if (chr['e'] > 0 && chr['i'] > 0 && chr['g'] > 0 && chr['h'] > 0 && chr['t'] > 0)
            {
                num[8]++;
                chr['e']--;
                chr['i']--;
                chr['g']--;
                chr['h']--;
                chr['t']--;
            } // eight
            if (chr['n'] > 1 && chr['i'] > 0 && chr['e'] > 0)
            {
                num[9]++;
                chr['n'] -= 2;
                chr['i']--;
                chr['e']--;
            } // nine
        }

        for (int index = 0; index < 10; index++)
            for (int j = 0; j < num[index]; j++)
                result += std::to_string(index);

        return result;
    }
};

int main()
{
    Solution solution;

    std::cout << solution.originalDigits("oneonetwotwothreethreefourfourfivefivesixsixsevenseveneighteightnineninezerozero") << std::endl;

    return 0;
}