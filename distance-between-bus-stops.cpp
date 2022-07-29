#include <iostream>
#include <vector>

using namespace std;

class Solution 
{

public:

    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) 
    {
        int distanceA = 0, distanceB = 0, curr = start;

        for (;;)
        {
            distanceA += distance[curr];

            curr += 1;
            curr %= distance.size();

            if (curr == destination) break;
        }

        for (;;)
        {
            distanceB += distance[curr];

            curr += 1;
            curr %= distance.size();

            if (curr == start) break;
        }

        return min(distanceA, distanceB);
    }

};

int main()
{
    return 0;
}