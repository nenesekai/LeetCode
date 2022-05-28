#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:

    string answerKey;
    int k;

    int maxConsecutiveChars(char chr)
    {
        int k = this->k, left = 0, right = -1, max = 0;

        while (right != answerKey.size())
        {
            right++;
            
            if (answerKey[right] != chr)
            {
                if (k == 0)
                {
                    max = std::max(max, right - left);

                    while (answerKey[left] == chr)
                    {
                        left++;
                    }

                    left++;
                }
                else
                {
                    k--;
                }
            }
        }

        return std::max(max, right - left + 1);
    }   

    int maxConsecutiveAnswers(string answerKey, int k) 
    {
        this->answerKey = answerKey;
        this->k         = k;

        return max(maxConsecutiveChars('T'), maxConsecutiveChars('F'));
    }

};

int main()
{   
    string key = "TTFTTFTT";
    int k = 1;

    Solution solution;

    cout << solution.maxConsecutiveAnswers(key, k) << endl;

    return 0;
}