#include "graph.h"
using namespace std;
class Graph
{
private:
    vector<vector<pair<int, int>>> G;

public:
    using ll = long long;
#define oo LLONG_MAX
    Graph(int n, vector<vector<int>> &edges) : G(n)
    {
        int u, v, w;
        for (vector<int> edge : edges)
        {
            u = edge[0];
            v = edge[1];
            w = edge[2];
            G[u].push_back({v, w});
            // G[u].emplace_back(v, w);
        }
    }

    void addEdge(vector<int> edge)
    {
        int u, v, w;
        u = edge[0];
        v = edge[1];
        w = edge[2];
        G[u].push_back({v, w});
        // G[u].emplace_back(v, w);
    }

    int shortestPath(int node1, int node2)
    {
        vector<ll> distance(G.size(), oo);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        distance[node1] = 0LL;
        pq.push({0LL, node1});
        while (!pq.empty())
        {
            auto [len, vertex] = pq.top();
            pq.pop();

            if (len > distance[vertex])
            {
                continue;
            }

            for (const auto &[neighbor, weighted] : G[vertex])
            {
                if (distance[vertex] + weighted < distance[neighbor])
                {
                    distance[neighbor] = distance[vertex] + weighted;
                    pq.push({distance[neighbor], neighbor});
                }
            }
        }
        return distance[node2] == oo ? -1 : distance[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */