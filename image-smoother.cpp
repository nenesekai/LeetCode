#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:

    vector<vector<int>> imageSmoother(vector<vector<int>>& img)
    {
        if (img.size() == 0 || img[0].size() == 0) return img;
        
        vector<vector<int>> result(img.size(), vector<int>(img[0].size()));

        for (int i = 0; i < img.size(); i++)
        {
            for (int j = 0; j < img[i].size(); j++)
            {
                int total = 0, count = 0;

                if (i != 0) 
                {
                    if (j != 0) 
                    {
                        total += img[i-1][j-1];
                        count++;
                    }

                    if (j != img[i].size() - 1)
                    {
                        total += img[i-1][j+1];
                        count++;
                    }

                    total += img[i-1][j];
                    count++;
                }

                if (j != 0) 
                {
                    total += img[i][j-1];
                    count++;
                }

                if (j != img[i].size() - 1)
                {
                    total += img[i][j+1];
                    count++;
                }

                total += img[i][j];
                count++;

                if (i != img.size() - 1) 
                {
                    if (j != 0) 
                    {
                        total += img[i+1][j-1];
                        count++;
                    }

                    if (j != img[i].size() - 1)
                    {
                        total += img[i+1][j+1];
                        count++;
                    }

                    total += img[i+1][j];
                    count++;
                }

                result[i][j] = (int) (total / count);
            }
        }

        return result;
    }

};

int main()
{
    vector<vector<int>> img{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    Solution solution;

    auto result = solution.imageSmoother(img);

    for (auto row : result)
    {
        for (auto pixel : row) 
        {
            cout << pixel << " ";
        }

        cout << endl;
    }

    return 0;
}