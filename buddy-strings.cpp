#include <iostream>
#include <map>

class Solution 
{
public:
    bool buddyStrings(std::string s, std::string goal) 
    {
        int index1 = -1, index2 = -1;

        if (s.length() != goal.length()) return false;

        for (int str_index = 0; str_index < s.length(); str_index++)
        {
            if (goal[str_index] != s[str_index])
            {
                if (index2 != -1)
                {
                    return false;
                }
                else if (index1 == -1)
                {
                    index1 = str_index;
                    continue;
                }
                else
                {
                    index2 = str_index;
                    continue;
                }
            }
        }

        if (index1 == -1)
        {
            std::map<char, bool> appeared;
            
            for (int index = 0; index < s.length(); index++)
            {
                if (appeared[s[index]])
                {
                    return true;
                }
                else
                {
                    appeared[s[index]] = true;
                }
            }

            return false;
        }

        if (index2 == -1) return false;
        if (s[index1] == goal[index2] && s[index2] == goal[index1]) return true;

        return false;
    }
};

int main()
{
    Solution solution;

    std::cout << (solution.buddyStrings("abcaa", "abcbb") ? "yes" : "no") << std::endl;

    return 0;
}