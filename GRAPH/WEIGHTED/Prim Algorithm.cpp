//! https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
#include "weighted.h"
#define oo LLONG_MAX

using namespace std;
struct Edge
{
    int start;
    int end;
    int weight;
};
// O((V + E)⋅logV)
void Prim_(vector<vector<pair<int, int>>> &G, int N, vector<bool> &used, int startVertex)
{
    long long W = 0LL;
    vector<Edge> MST;
    used[startVertex] = true;
    while (MST.size() < N - 1)
    {
        int min_W = INT_MAX;
        int u = 0;
        int v = 0;
        for (int vertex = 1; vertex <= N; vertex++)
        {
            if (used[vertex])
            {
                for (auto [neighbor, weighted] : G[vertex])
                {
                    if (!used[neighbor] && weighted < min_W)
                    {
                        min_W = weighted;
                        u = vertex;
                        v = neighbor;
                    }
                }
            }
        }
        W += (long long)min_W;
        MST.push_back({u, v, min_W});
        used[v] = true;
    }
    cout << "Weighted = " << W << endl;
    cout << "List of Edges: \n";
    for (auto edge : MST)
    {
        cout << edge.start << " " << edge.end << " : " << edge.weight << endl;
    }
}
// O(ElogE) + O(V) ≈ O(ElogE)
void Prim(vector<vector<pair<int, int>>> &G, int N, vector<bool> &used, int startVertex)
{
    long long W = 0LL;
    vector<Edge> MST;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQueue;

    PQueue.push({0, startVertex});

    while (!PQueue.empty() && MST.size() < N - 1)
    {
        pair<int, int> wv = PQueue.top();
        PQueue.pop();

        if (used[wv.second])
        {
            continue;
        }

        W += wv.first;
        used[wv.second] = true;

        for (auto [vertex, weighted] : G[wv.second])
        {
            if (!used[vertex])
            {
                PQueue.push({weighted, vertex});
            }
        }
    }
    cout << "Weighted = " << W << endl;
}
int main()
{
    io;
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);

    int N, M;
    cin >> N >> M;
    int u, v, w;
    vector<vector<pair<int, int>>> G(N + 1);
    vector<bool> used(N + 1, false);
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w}); // Undirected Graph
    }
    Prim_(G, N, used, 1);
    fill(used.begin(), used.end(), false);
    Prim(G, N, used, 1);
    return 0;
}