#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int count = 0;

        for (string word : words)
        {
            if (word.size() < pref.size()) continue;

            if (word.substr(0, pref.size()) == pref) count++;
        }

        return count;
    }
};

int main()
{
    vector<string> words = {"pay", "attention", "practice", "attend"};

    Solution* obj = new Solution();

    cout << obj->prefixCount(words, "at") << endl;

    delete obj;

    return 0;
}