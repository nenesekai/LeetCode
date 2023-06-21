#include <iostream>

using namespace std;

class Solution
{
private:
    struct Words
    {
        struct Word
        {
            string word;
            int f;
            Word *next;

            Word(string &word)
                : word(word), f(Solution::f(word)), next(nullptr)
            {}
        };

        int size;
        Word *head;

        Words() : size(0), head(nullptr) {}

        void insert(string &wordstr)
        {
            Word *word = new Word(wordstr);
            insert(word);
        }

        void insert(Word *word)
        {
            if (!head) // when there are no word at all
            {
                head = word;
                ++size;
                return;
            }

            if (head->f > word->f) // compare with the first word
            {
                word->next = head;
                head = word;
                ++size;
                return;
            }

            Word* curr = head;
            while (curr->next) // compare with the rest of the words
            {
                if (curr->next->f > word->f)
                {
                    word->next = curr->next;
                    curr->next = word;
                    ++size;
                    return;
                }
                curr = curr->next;
            }
            curr->next = word; // when no words are larger
            ++size;
            return;
        }

        int query(string &query)
        {
            int result = size;
            Word *curr = head;
            int f = Solution::f(query);
            if (query == "abaaaaaa")
            {}
            while (result > 0)
            {
                if (curr->f <= f) 
                {
                    --result;
                    curr = curr->next;
                }
                else
                {
                    break;
                }
            }
            return result;
        }
    };
public:
    static int f(string &s)
    {
        char min = s[0];
        int count = 1;
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] < min)
            {
                min = s[i];
                count = 1;
            }
            else if (s[i] == min)
            {
                ++count;
            }
        }
        return count;
    }
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words_str)
    {
        Words words;
        vector<int> results;
        for (string word : words_str)
        {
            words.insert(word);
        }
        for (string query : queries)
        {
            results.push_back(words.query(query));
        }
        return results;
    }
};

int main()
{
    vector<string> queries = {"bba","abaaaaaa","aaaaaa","bbabbabaab","aba","aa","baab","bbbbbb","aab","bbabbaabb"};
    vector<string> words = {"aaabbb","aab","babbab","babbbb","b","bbbbbbbbab","a","bbbbbbbbbb","baaabbaab","aa"};
    Solution *obj = new Solution();
    vector<int> results = obj->numSmallerByFrequency(queries, words);
    for (int result : results) cout << result << " ";
    cout << endl;
    delete obj;
    return 0;
}