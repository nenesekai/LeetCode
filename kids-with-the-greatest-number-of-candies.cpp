#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        if (candies.empty()) return vector<bool>();
        int max = candies[0];
        for (int i = 1; i < candies.size(); ++i)
        {
            if (max < candies[i]) max = candies[i];
        }
        vector<bool> results(candies.size(), false);
        for (int i = 0; i < candies.size(); ++i)
        {
            if (candies[i] + extraCandies >= max)
            {
                results[i] = true;
            }
        }
        return results;
    }
};

int main()
{
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    Solution *obj = new Solution();
    vector<bool> results = obj->kidsWithCandies(candies, extraCandies);
    for (bool result : results)
    {
        cout << (result ? "True" : "False") << " ";
    }
    cout << endl;
    delete obj;
    return 0;
}