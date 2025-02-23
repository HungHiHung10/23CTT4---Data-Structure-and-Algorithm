#include "graph.h"
using namespace std;
class Solution
{
public:
#define oo INT_MAX
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> G(n);
        for (const auto &flight : flights)
        {
            int u = flight[0], v = flight[1], w = flight[2];
            G[u].emplace_back(v, w);
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, 0, src);

        vector<vector<int>> dist(n, vector<int>(k + 2, oo));
        dist[src][0] = 0;

        while (!pq.empty())
        {
            auto [cost, stops, vertex] = pq.top();
            pq.pop();
            if (vertex == dst)
                return cost;

            if (stops > k)
                continue;

            for (const auto &[neighbor, weighted] : G[vertex])
            {
                if (cost + weighted < dist[neighbor][stops + 1])
                {
                    dist[neighbor][stops + 1] = cost + weighted;
                    pq.emplace(dist[neighbor][stops + 1], stops + 1, neighbor);
                }
            }
        }
        return -1;
    }
};
