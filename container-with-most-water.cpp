#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
    
    int ptr_left, ptr_right, max;

    int calculate_area(int left, int right, vector<int>* height)
    {
        return min(height.at(left), height->at(right)) * (ptr_right - ptr_left);
    }

    int maxArea(vector<int>& height)
    {
        ptr_left = 0;
        ptr_right = height.size() - 1;

        max = 0;

        while (ptr_left < ptr_right)
        {
            if (max < calculate_area(&height))
        }
    }

};

int main()
{
    Solution* solution = new Solution();

    vector<int> height {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << solution->maxArea(height) << endl;

    return 0;
}