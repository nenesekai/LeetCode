#include <iostream>

class Solution
{

public:

    void reverse_word(std::string& word)
    {
        if (word.length() < 2) return;
        auto l_ptr = word.begin(), r_ptr = word.end() - 1;

        while (l_ptr + 1 <= r_ptr)
        {
            std::swap(*l_ptr, *r_ptr);

            l_ptr++;
            r_ptr--;
        }
    }

    std::string reverseWords(std::string s)
    {
        std::string result = "", word = "";

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                reverse_word(word);
                result += word + " ";
                word = "";
            }
            else
            {
                word += s[i];
            }
        }

        reverse_word(word);
        result += word;

        return result;
    }

};

int main()
{
    Solution solution;

    std::string word = "your mother died yesterday";
    std::cout << solution.reverseWords(word) << std::endl;

    return 0;
}