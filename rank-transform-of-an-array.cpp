#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution 
{

public:

    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        vector<int> sortedArr = arr;

        sort(sortedArr.begin(), sortedArr.end());

        unordered_map<int, int> order;

        vector<int> ans(arr.size());

        for (int &num : sortedArr)
        {
            if (!order.count(num))
            {
                order[num] = order.size() + 1;
            }
        }

        for (int i = 0; i < arr.size(); i++)
        {
            ans[i] = order[arr[i]];
        }

        return ans;
    }

};

int main()
{

}