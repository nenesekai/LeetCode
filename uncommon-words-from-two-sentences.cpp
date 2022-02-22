#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution 
{

public:

    vector<string> uncommonFromSentences(string s1, string s2) 
    {
        map<string, int> word_count;
        vector<string> result;

        string word_buffer = "";
        for (int i = 0; i < s1.size(); i++) 
        {
            if (s1[i] != ' ')
            {
                word_buffer += s1[i];
            }
            else
            {
                word_count[word_buffer]++;
                word_buffer = "";
            }
        }

        if (word_buffer != "")
        {
            word_count[word_buffer]++;
            word_buffer = "";
        }

        for (int i = 0; i < s2.size(); i++)
        {
            if (s2[i] != ' ')
            {
                word_buffer += s2[i];
            }
            else
            {
                word_count[word_buffer]++;
                word_buffer = "";
            }
        }

        if (word_buffer != "")
        {
            word_count[word_buffer]++;
            word_buffer = "";
        }

        for (auto iter = word_count.begin(); iter != word_count.end(); iter++)
        {
            if (iter->second == 1)
            {
                result.push_back(iter->first);
            }
        }

        return result;
    }

};

int main() 
{
    Solution solution;

    vector<string> uncommon_words = solution.uncommonFromSentences("This apple is sweet", "This apple is sour");

    for (auto iter = uncommon_words.begin(); iter < uncommon_words.end(); iter++)
    {
        cout << *iter << endl;
    }

    return 0;
}