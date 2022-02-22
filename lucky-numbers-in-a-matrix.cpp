#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:

    vector<int> luckyNumbers(vector<vector<int>>& matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0) return vector<int>{};

        int n1 = matrix.size(), n2 = matrix[0].size();

        vector<int> lucky_nums;

        for (int i = 0; i < n1; i++)
        {
            int min_index = 0;

            for (int j = 1; j < n2; j++)
            {
                if (matrix[i][j] < matrix[i][min_index])
                {
                    min_index = j;
                }
            }

            bool is_max = true;

            for (int i2 = 0; i2 < n1; i2++)
            {
                if (matrix[i2][min_index] > matrix[i][min_index])
                {
                    is_max = false;
                    break;
                }
            }

            if (is_max) lucky_nums.push_back(matrix[i][min_index]);
        }

        return lucky_nums;
    }
    
};

int main()
{
    vector<vector<int>> matrix = {{3, 7, 8}, {9, 11, 13}, {15, 16, 17}};

    Solution* solution = new Solution();

    auto result = solution->luckyNumbers(matrix);

    for (auto iter = result.begin(); iter < result.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}