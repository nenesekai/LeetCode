#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
    string truncateSentence(string s, int k) 
    {
        int count = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s.at(i) == ' ') count++;
            if (count == k) return s.substr(0, i);
        }

        return s;
    }
};

int main()
{
    return 0;
}