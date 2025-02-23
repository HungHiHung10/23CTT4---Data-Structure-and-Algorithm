//! https://howkteam.vn/course/cau-truc-du-lieu-va-giai-thuat/tim-kiem-duong-di-ngan-nhat-tren-do-thi-dijikstra-4387
//! https://viblo.asia/p/thuat-toan-dijkstra-va-ung-dung-aWj53zgQl6m
//* Can be applied only to negative weight graph
#include "weighted.h"
#define oo LLONG_MAX

using namespace std;

void Bellman_Ford(vector<vector<pair<int, int>>> &G, int N, int source, int destination)
{
    vector<long long> distance(N + 1, oo);
    distance[source] = 0LL;
    for (int vertex = 1; vertex <= N; vertex++)
    {
        for (auto [neighbor, weighted] : G[vertex])
        {
            if (distance[vertex] != oo && distance[vertex] + weighted < distance[neighbor])
            {
                if (vertex != N - 1)
                {
                    break;
                }
            }
            distance[neighbor] = distance[vertex] + weighted;
        }
    }
}
int main()
{
    io;
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);

    int N, M, u, v, w;
    cin >> N >> M;
    vector<vector<pair<int, int>>> Graph(N + 1);
    // vector<bool> visited(N + 1);
    vector<bool> marked(N + 1, false);
    vector<long long> distance(N + 1, oo);
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        Graph[u].push_back(make_pair(v, w));
    }
    // for (int vertex = 1; vertex <= N; vertex++)
    // {
    //     cout << vertex << " : \n";
    //     for (auto neighbor : Graph[vertex])
    //     {
    //         cout << '\t' << neighbor.first << " - " << neighbor.second << '\n';
    //     }
    //     cout << endl;
    // }
    // Dijkstra(Graph, marked, distance, 1, N);

    // for (int i = 1; i <= N; i++)
    // {
    //     cout << distance[i] << " ";
    // }
    return 0;
}
