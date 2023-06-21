#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k)
    {
        vector<pair<int, int>> diff(reward1.size());
        int result = 0;
        for (int i = 0; i < reward1.size(); i++)
        {
            diff[i] = pair<int, int>(i, reward1[i] - reward2[i]);
        }
        sort(diff.begin(), diff.end(),
             [](const pair<int, int> &lhs, const pair<int, int> &rhs) -> bool
             {
                 return lhs.second > rhs.second;
             });
        for (int i = 0; i < k; i++)
        {
            result += reward1[diff[i].first];
        }
        for (int i = k; i < reward1.size(); i++)
        {
            result += reward2[diff[i].first];
        }
        return result;
    }
};

int main()
{
    vector<int> reward1 = {1, 1, 3, 4};
    vector<int> reward2 = {4, 4, 1, 1};
    int k = 2;

    // -3 -3 2 3

    Solution *obj = new Solution();

    cout << obj->miceAndCheese(reward1, reward2, k) << endl;

    delete obj;

    return 0;
}