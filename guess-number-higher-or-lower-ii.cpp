#include <iostream>

using namespace std;

class Solution 

{
public:
    int getMoneyAmount(int n) 
    {
        int ptr = n / 2, money = ptr;
        cout << ptr << endl;

        while (ptr + 2 < n)
        {
            ptr = (n - ptr) / 2 + ptr;
            cout << ptr << endl;
            money += ptr;
        }

        cout << endl;
        
        return ptr;
    }

};

int main()
{
    Solution solution;
    cout << solution.getMoneyAmount(10) << endl;
    return 0;
}