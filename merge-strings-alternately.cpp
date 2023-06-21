#include <iostream>
#include <sstream>

using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int pt1 = 0, pt2 = 0;
        stringstream ss;
        while (pt1 < word1.size() && pt2 < word2.size())
        {
            ss << word1[pt1] << word2[pt2];
            ++pt1;
            ++pt2;
        }
        if (pt1 < word1.size()) ss << word1.substr(pt1);
        if (pt2 < word2.size()) ss << word2.substr(pt2);
        return ss.str();
    }
};

int main()
{
    return 0;
}