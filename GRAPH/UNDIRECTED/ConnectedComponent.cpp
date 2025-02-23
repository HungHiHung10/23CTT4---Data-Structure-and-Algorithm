#include "undirected.h"
struct Adjacency
{
    set<int> vertices;
};
struct Edge
{
    pair<int, int> edges;
};
void DFS(vector<Adjacency> listAdj, vector<bool> &visited, int vertex)
{
    cout << vertex << " ";
    visited[vertex] = true;
    for (int neighbor : listAdj[vertex].vertices)
    {
        if (!visited[neighbor])
        {
            DFS(listAdj, visited, neighbor);
        }
        if (crash++ > 1000)
            return;
    }
}
int main()
{
    io;
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);

    int N, M;
    cin >> N >> M;
    int N, M;
    cin >> N >> M;
    vector<Adjacency> listAdj(N + 1);
    vector<bool> visited(N + 1, false);
    int connectedComponent = 0;

    int vertexStart, vertexEnd;
    for (int i = 0; i < M; i++)
    {
        cin >> vertexStart >> vertexEnd;
        listAdj[vertexStart].vertices.insert(vertexEnd);
        listAdj[vertexEnd].vertices.insert(vertexStart);
    }
    for (int i = 1; i <= N; i++)
    {
        if (visited[i])
        {
            DFS(listAdj, visited, i);
            connectedComponent++;
        }
    }
    cout << connectedComponent;
    return 0;
}