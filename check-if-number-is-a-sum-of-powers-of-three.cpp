#include <iostream>

using namespace std;

class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        while (n != 0)
        {
            if (n % 3 == 2)
            {
                return false;
            }
            n /= 3;
        }

        return true;
    }
};

int main()
{
    Solution* obj = new Solution();

    cout << obj->checkPowersOfThree(21) << endl;

    delete obj;

    return 0;
}
