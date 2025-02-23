#include "Cycle.h"
using namespace std;
bool detectCyclebyBFS(vector<vector<int>> &G, vector<bool> &visited, int vertex)
{
    queue<int> Q;
    Q.push(vertex);

    // cout << vertex << endl;
    while (!Q.empty())
    {
        int vertex = Q.front();
        Q.pop();

        if (visited[vertex])
        {
            return true;
        }
        visited[vertex] = true;

        for (int neighbor : G[vertex])
        {
            if (!visited[neighbor])
            {
                Q.push(neighbor);
            }
        }
    }
    return false;
}
int main()
{
    if (fopen(input, "r"))
    {
        freopen(input, "r", stdin);
        freopen(output, "w", stdout);
    }
    int V, E, u, v;
    cin >> V >> E;
    vector<vector<int>> G(V + 1);
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<bool> visited(E, false);

    for (int i = 1; i <= V; i++)
    {
        if (!visited[i] && detectCyclebyBFS(G, visited, i))
        {
            cout << "TRUE";
            return 0;
        }
    }
    cout << "FALSE";
    return 0;
}