#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:

    int countGoodRectangles(vector<vector<int>>& rectangles)
    {
        int max = 0, max_count = 0;

        for (auto iter = rectangles.begin(); iter < rectangles.end(); iter++)
        {
            int min_side = min(iter->front(), iter->back());

            if (min_side > max)
            {
                max_count = 1;
                max = min_side;
            }
            else if (min_side == max)
            {
                max_count++;
            }
        }

        return max_count;
    }

};

int main()
{
    vector<vector<int>> rectangles{{5, 8}, {3, 9}, {5, 12}, {16, 5}};
    Solution solution;

    cout << solution.countGoodRectangles(rectangles) << endl;

    return 0;
}