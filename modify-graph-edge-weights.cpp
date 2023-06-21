#include <iostream>
#include <queue>
#include <set>

using namespace std;

struct Edge
{
    int vert1, vert2, weight;
    Edge(int vert1, int vert2, int weight) : vert1(vert1), vert2(vert2), weight(weight) {}
};

struct Path
{
    int dist, unknowns;
    set<Edge *> edges;
    Path() : dist(INT_MAX), unknowns(0), edges() {}
};

class Solution
{
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int source, int destination, int target)
    {
        // Converting edges to objects
        vector<set<Edge *>> adj(n);
        for (vector<int> edge : edges)
        {
            Edge *obj_edge = new Edge(edge[0], edge[1], edge[2]);
            adj[obj_edge->vert1].insert(obj_edge);
            adj[obj_edge->vert2].insert(obj_edge);
        }

        // Using SSSP to Find Shortest Path with Least -1 weighted edges
        auto comp = [](const Path &lhs, const Path &rhs)
        {
            if (lhs.dist == rhs.dist)
            {
                return lhs.dist > rhs.dist;
            }
            else
            {
                return lhs.unknowns > rhs.unknowns;
            }
        };
        priority_queue<pair<int, Path>, vector<pair<int, Path>>, decltype(comp)> pq(comp);
        
        for (int i = 0; i < n; i++) 
        {
            if (i == source)
            {
                pq.push
            }
        }
    }
};

int main()
{
    return 0;
}