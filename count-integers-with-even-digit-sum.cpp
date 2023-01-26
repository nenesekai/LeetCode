#include <iostream>

using namespace std;

class Solution
{
public:
    int countEven(int num)
    {
        int sum = 0, temp = 0, ret = 0;

        for (int i = 1; i <= num; i++)
        {
            temp = i; sum = 0;

            while (temp != 0)
            {
                sum += temp % 10;
                temp /= 10;
            }

            if (sum % 2 == 0) ret++;
        }

        return ret;
    }
};

int main()
{
    Solution* obj = new Solution();

    cout << obj->countEven(30) << endl;

    delete obj;

    return 0;
}