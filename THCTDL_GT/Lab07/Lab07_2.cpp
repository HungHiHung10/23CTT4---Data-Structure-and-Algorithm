#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <utility>
#include <climits>
#define Input "Lab07.in"
#define Output "Lab07.out"
#define oo LLONG_MAX
using namespace std;
vector<long long> Dijkstra(vector<vector<pair<int, int>>> &G, int N, int source)
{
    vector<long long> distance(N, oo);
    distance[source] = 0LL;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> PQueue;
    PQueue.push({0LL, source});
    while (!PQueue.empty())
    {
        auto [length, vertex] = PQueue.top();
        PQueue.pop();

        if (distance[vertex] < length)
        {
            continue;
        }

        for (auto [neighbor, weighted] : G[vertex])
        {
            if (distance[vertex] + weighted < distance[neighbor])
            {
                distance[neighbor] = distance[vertex] + weighted;
                PQueue.push({distance[neighbor], neighbor});
            }
        }
    }
    return distance;
}
long long Prim(vector<vector<pair<int, int>>> &G, int N)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQueue;
    PQueue.push({0LL, 0});
    vector<bool> used(N, false);
    long long W = 0LL;
    vector<pair<int, int>> MST;

    while (!PQueue.empty())
    {
        auto [weighted, vertex] = PQueue.top();
        PQueue.pop();

        if (used[vertex])
        {
            continue;
        }
        used[vertex] = true;
        W += weighted;
        MST.push_back(vertex, weighted);
        for (auto [neighbor, weight] : G[vertex])
        {
            if (!used[neighbor])
            {
                PQueue.push({weight, neighbor});
            }
        }
    }
    for (auto [v, w] : MST)
    {
        cout << v << " " << w << endl;
    }
    return W;
}
int main()
{
    freopen(Input, "r", stdout);
    freopen(Output, "w", stdout);
    int N, M, u, v;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int source = 1;
    int destination = 5;
    BreadthFirstSearch(G, N, source, destination);
    DepthFirstSearch(G, N, source, destination);
    return 0;
}
