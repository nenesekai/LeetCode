#include <iostream>

using namespace std;

class Solution
{
public:
    int countVowelStrings(int n, int max = 5)
    {
        if (n == 1)
        {
            return max;
        }

        int sum = 0;

        for (int i = max; i >= 1; i--)
        {
            sum += countVowelStrings(n - 1, i);
        }

        return sum;
    }
};

int main()
{
    int n = 1;
    Solution *obj = new Solution();
    cout << obj->countVowelStrings(n) << endl;
    delete obj;
    return 0;
}