#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution
{

public:

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load)
    {
        set<int> idle;

        for (int server_iter = 0; server_iter < k; server_iter++)
        {
            idle.insert(server_iter);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;

        vector<int> handled(k);

        for (int task_iter = 0; task_iter < load.size(); task_iter++)
        {
            int time = arrival[task_iter];

            while (!busy.empty() && busy.top().first <= time)
            {
                idle.insert(busy.top().second);
                busy.pop();
            }

            if (idle.empty()) continue;

            auto process_server = idle.lower_bound(task_iter % k);

            if (process_server == idle.end()) process_server = idle.begin();

            handled[*process_server]++;

            busy.emplace(time + load[task_iter], *process_server);

            idle.erase(*process_server);
        }

        int max_handled = *max_element(handled.begin(), handled.end());

        vector<int> busiest_servers;

        for (int server_iter = 0; server_iter < k; server_iter++)
        {
            if (handled[server_iter] == max_handled) 
            {
                busiest_servers.push_back(server_iter);
            }
        }

        return busiest_servers;
    }

};

int main()
{
    int k = 3;
    vector<int> arrival{1, 2, 3, 4, 8, 9, 10}, load{5, 2, 10, 3, 1, 2, 2};

    Solution solution;

    vector<int> busiest_servers = solution.busiestServers(k, arrival, load);

    for (int busiest_server : busiest_servers)
    {
        cout << busiest_server << " ";
    }
    cout << endl;

    return 0;
}