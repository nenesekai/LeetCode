#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string result;
        int extra = 0;
        cout << num1.length() << " " << num1.size() << endl;
        for (int pt = 1; pt <= max(num1.size(), num2.size()); ++pt)
        {
            int digit1 = pt > num1.size() ? 0 : (num1[num1.size() - pt] - '0'),
                digit2 = pt > num2.size() ? 0 : (num2[num2.size() - pt] - '0');
            if (digit1 + digit2 + extra > 9)
            {
                result = to_string(digit1 + digit2 + extra - 10) + result;
                extra = 1;
            }
            else
            {
                result = to_string(digit1 + digit2 + extra) + result;
                extra = 0;
            }
        }
        return (extra ? "1" : "") + result;
    }
};

int main()
{
    string num1 = "11", num2 = "123";
    Solution *obj = new Solution();
    cout << obj->addStrings(num1, num2) << endl;
    delete obj;
    return 0;
}