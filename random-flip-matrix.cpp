#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution 
{

private:

    vector<vector<int>> zero;
    vector<vector<int>>::iterator zero_iter;
    int zero_count, m, n;

public:

    Solution(int m, int n)
        : m(m), n(n)
    {
        reset();
    }
    
    vector<int> flip() 
    {
        int rand_ptr = rand() % zero_count;
        auto flipped = zero[rand_ptr];

        zero.erase(zero.begin() + rand_ptr);
        zero_count--;

        cout << flipped[0] << " " << flipped[1] << endl;

        return flipped;
    }
    
    void reset() 
    {
        zero = vector<vector<int>>(m * n);
        zero_iter = zero.begin();
        zero_count = m * n;

        for (int x = 0; x < m; x++)
        {
            for (int y = 0; y < n; y++)
            {
                *zero_iter = vector<int>{x, y};
                zero_iter++;
            }
        }
    }

};

int main()
{
    Solution* solution = new Solution(3, 1);

    solution->flip();
    solution->flip();
    solution->flip();
    solution->reset();
    solution->flip();

    return 0;
}