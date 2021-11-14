#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:

    void rotate(vector<vector<int>>& matrix) {
        for (int sides = matrix.size(); sides > 1; sides -= 2)
        {
            int start = (matrix.size() - sides) / 2
                , end = start + sides - 1;

            for (int i = 0; i < sides - 1; i++)
            {
                int *container = new int(matrix[start][start + i]);
                matrix[start][start + i] = matrix[end - i][start];
                matrix[end - i][start] = matrix[end][end - i];
                matrix[end][end - i] = matrix[start + i][end];
                matrix[start + i][end] = *container;
                delete container;
            }
        }
    }

};

void printMatrix(vector<vector<int>>& matrix)
{
    for (vector<vector<int>>::iterator iter = matrix.begin(); iter < matrix.end(); iter++)
    {
        for (vector<int>::iterator iter2 = (*iter).begin(); iter2 < (*iter).end(); iter2++)
        {
            cout << *iter2 << "\t";
        }

        cout << endl;
    }
}

int main()
{
    Solution solution;

    vector<vector<int>> matrix{
        vector<int>{1, 2, 3, 4, 5, 6}
        , vector<int>{7, 8, 9, 10, 11, 12}
        , vector<int>{13, 14, 15, 16, 17, 18}
        , vector<int>{19, 20, 21, 22, 23, 24}
        , vector<int>{25, 26, 27, 28, 29, 30}
        , vector<int>{31, 32, 33, 34, 35, 36}};

    printMatrix(matrix);
    cout << endl;

    solution.rotate(matrix);

    printMatrix(matrix);
    cout << endl;

    return 0;
}