#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        if (numbers.size() < 2) return {-1, -1};
        if (numbers.size() == 2) return {1, 2};
        int begin = 0, end = numbers.size() - 1;
        while (begin < end)
        {
            int sum = numbers[begin] + numbers[end];
            if (sum == target) return {begin + 1, end + 1};
            if (sum < target) ++begin;
            else if (sum > target) --end;
        }
        return {-1, -1};
    }
};

int main()
{
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    Solution *obj = new Solution();
    auto results = obj->twoSum(numbers, target);
    cout << results[0] << " " << results[1] << endl;
    delete obj;
    return 0;
}