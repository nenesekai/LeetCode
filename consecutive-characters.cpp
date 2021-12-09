#include <iostream>

using namespace std;

class Solution 
{
public:
    int maxPower(string s) 
    {
        if (s.size() == 1) return 1;

        int count = 1, max = 1;

        for (int ptr = 1; ptr < s.size(); ptr++)
        {
            if (s.at(ptr) == s.at(ptr - 1))
            {
                count++;
            }
            else
            {
                if (count > max) max = count;
                count = 1;
            }
        }

        return std::max(count, max);
    }
};

int main()
{
    return 0;
}