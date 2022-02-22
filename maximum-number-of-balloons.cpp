#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:

    int maxNumberOfBalloons(string text)
    {
        vector<int> count(26);

        for (int i = 0; i < text.length(); i++)
        {
            count[text[i] - 'a']++;
        }

        int min = count['b' - 'a'];

        min = std::min(count['a' - 'a'], min);
        min = std::min(count['l' - 'a'] / 2, min);
        min = std::min(count['o' - 'a'] / 2, min);
        min = std::min(count['n' - 'a'], min);

        return min;
    }

};

int main()
{
    Solution* solution = new Solution();

    cout << solution->maxNumberOfBalloons("loonbalxballpoon") << endl;

    return 0;
}