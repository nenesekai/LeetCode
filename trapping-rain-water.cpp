#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        for (int i = 0; i < height.size(); ++i)
        {

        }
    }
};

int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution *obj = new Solution();
    cout << obj->trap(height) << endl;
    delete obj;
    return 0;
}