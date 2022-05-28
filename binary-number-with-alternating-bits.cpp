#include <iostream>
#include <bitset>

using namespace std;

class Solution
{

public:

    bool hasAlternatingBits(int n)
    {
        bitset<10> bit(n);

        string binary = bit.to_string();

        int ptr = 0;

        while (binary[ptr] == '0')
        {
            binary = binary.substr(1, binary.size() - 1);
        }

        for (int i = 1; i < binary.size(); i++)
        {
            if (binary[i] == binary[i-1]) return false;
        }

        return true;
    }

};

int main()
{
    Solution solution;

    solution.hasAlternatingBits(114);

    return 0;
}