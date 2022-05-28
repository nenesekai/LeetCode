#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{

public:

    char nextGreatestLetter(vector<char>& letters, char target)
    {
        vector<char>::iterator rt = upper_bound(letters.begin(), letters.end(), target);

        return rt == letters.end() ? letters.front() : *rt;
    }

};

int main()
{
    vector<char> letters{'c', 'f', 'j'};
    char target = 'j';

    Solution solution;

    cout << solution.nextGreatestLetter(letters, target) << endl;

    return 0;
}