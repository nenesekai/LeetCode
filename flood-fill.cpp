#include <iostream>
#include <vector>

using namespace std;

class Solution 
{

public:

    vector<vector<int>> floodFill(vector<vector<int>> image, int sr, int sc, int new_color) 
    {
        int original_color = image[sr][sc];
        image[sr][sc] = new_color;

        if (sr != 0 && image[sr - 1][sc] == original_color) image = floodFill(image, sr - 1, sc, new_color);
        if (sc != 0 && image[sr][sc - 1] == original_color) image = floodFill(image, sr, sc - 1, new_color);
        if (sr != image.size() - 1 && image[sr + 1][sc] == original_color) image = floodFill(image, sr + 1, sc, new_color);
        if (sc != image[0].size() - 1 && image[sr][sc + 1] == original_color) image = floodFill(image, sr, sc + 1, new_color);

        return image;
    }
    
};

int main()
{
    Solution solution;
    vector<vector<int>> image{{0, 0, 0}, {0, 0, 0}};
    int sr = 0, sc = 0, new_color = 2;

    image = solution.floodFill(image, sr, sc, new_color);

    for (auto i = image.begin(); i < image.end(); i++)
    {
        for (auto j = i->begin(); j < i->end(); j++)
        {
            cout << *j << " ";
        }
        cout << endl;
    }

    return 0;
}