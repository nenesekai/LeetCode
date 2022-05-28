#include <iostream>
#include <vector>

using namespace std;

class Solution 
{

public:

    int maxArea(vector<int>& height) 
    {
        int max = 0;

        for (int i = 0; i < height.size() - 1; i++)
        {
            if (height[i] * (height.size() - 1 - i) > max) 
            {
                for (int j = i + 1; j < height.size(); j++)
                {
                    int area = min(height[i], height[j]) * (j - i);

                    if (area > max) max = area;
                }
            }
        }

        return max;
    }

};

int main()
{
    Solution* solution = new Solution();

    vector<int> height {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << solution->maxArea(height) << endl;

    return 0;
}