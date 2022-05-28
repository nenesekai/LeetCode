#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:

    vector<int> numberOfLines(vector<int>& widths, string s)
    {
        int line = 1, last_width = 0;

        for (char chr : s)
        {
            if (100 - last_width < widths[chr - 'a'])
            {
                line++;
                last_width = widths[chr - 'a'];
            }
            else
            {
                last_width += widths[chr - 'a'];
            }
        }

        return vector<int>{s.size() == 0 ? 0 : line, last_width};
    }

};

int main()
{
    vector<int> widths = {4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};

    Solution solution;

    vector<int> rt = solution.numberOfLines(widths, "bbbcccdddaaa");

    cout << rt[0] << " " << rt[1] << endl;

    return 0;
}