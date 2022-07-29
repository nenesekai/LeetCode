#include <iostream>
#include <vector>

using namespace std;

class Solution 
{

public:

    vector<string> reorderLogFiles(vector<string>& logs) 
    {

    }

};

int main()
{
    vector<string> logs = {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};

    Solution* obj = new Solution();

    vector<string> result = obj->reorderLogFiles(logs);

    for (string str : result)
    {
        cout << str << endl;
    }
    
    return 0;
}