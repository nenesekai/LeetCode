#include <iostream>
#include <vector>

using namespace std;

class Solution 
{

public:

    bool canConstruct(string ransomNote, string magazine) 
    {
        vector<int> chr_available(26);

        for (int ptr = 0; ptr < magazine.size(); ptr++)
        {
            chr_available[magazine.at(ptr) - 'a']++;
        }

        for (int ptr = 0; ptr < ransomNote.size(); ptr++)
        {
            chr_available[ransomNote.at(ptr)]--;

            if (chr_available[ransomNote.at(ptr) - 'a'] < 0) return false;
        }

        return true;
    }

};

int main()
{
    cout << (int) 'c' - 'a' << endl;

    return 0;
}