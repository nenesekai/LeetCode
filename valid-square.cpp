#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:

    bool isRightTriangle(vector<int>& p1, vector<int>& p2, vector<int>& p3)
    {
        int s1 = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
        int s2 = (p2[0] - p3[0]) * (p2[0] - p3[0]) + (p2[1] - p3[1]) * (p2[1] - p3[1]);
        int s3 = (p1[0] - p3[0]) * (p1[0] - p3[0]) + (p1[1] - p3[1]) * (p1[1] - p3[1]);

        if (
            s1 > s2 && s2 == s3 && s2 + s3 == s1 ||
            s2 > s1 && s1 == s3 && s1 + s3 == s2 ||
            s3 > s1 && s1 == s2 && s1 + s2 == s3
        )
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4)
    {
        return isRightTriangle(p1, p2, p3) && isRightTriangle(p1, p2, p4) && isRightTriangle(p1, p3, p4) && isRightTriangle(p2, p3, p4);
    }

};

int main()
{
    vector<int> p1 = {0, 0};
    vector<int> p2 = {1, 1};
    vector<int> p3 = {1, 0};
    vector<int> p4 = {0, 12};
    
    Solution* obj = new Solution();

    cout << obj->validSquare(p1, p2, p3, p4) << endl;

    return 0;
}