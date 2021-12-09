#include <iostream>
#include <vector>

class Solution 
{

public:

    void reverseString(std::vector<char>& s) 
    {
        if (s.size() < 2) return;

        auto iter_left = s.begin(), iter_right = s.end() - 1;

        while (iter_left + 1 <= iter_right)
        {
            *iter_left  ^= *iter_right;
            *iter_right ^= *iter_left;
            *iter_left  ^= *iter_right;

            iter_left++;
            iter_right--;
        }
    }

};

void print_chr_vec(std::vector<char>& s)
{
    for (auto s_ptr = s.begin(); s_ptr < s.end(); s_ptr++)
        std::cout << *s_ptr;

    std::cout << std::endl;
}

int main()
{
    Solution solution;
    std::vector<char> s{'h', 'e', 'l', 'l', 'o'};

    print_chr_vec(s);
    solution.reverseString(s);
    print_chr_vec(s);    

    return 0;
}