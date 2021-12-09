#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int tribonacci(int n) 
    {
        vector<int> tab(40);

        tab[0] = 0;
        tab[1] = 1;
        tab[2] = 1;

        if (n <= 2) return tab[n];

        for (int i = 3; i <= n; i++)
        {
            tab[i] = tab[i - 1] + tab[i - 2] + tab[i - 3];
        }

        return tab[n];
    }
};

int main()
{
    return 0;
}