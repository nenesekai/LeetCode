#include <iostream>
#include <vector>

using namespace std;


int main()
{
    Solution solution;

    vector<vector<int>> edges{{1, 2}, {2, 3}, {4, 2}};

    cout << solution.findCenter(edges) << endl;

    return 0;
}