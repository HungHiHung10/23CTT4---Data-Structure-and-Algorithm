//! https://takeuforward.org/graph/strongly-connected-components-kosarajus-algorithm-g-54/
// Strongly Connected Components(SCCs) in Directed Graph
#include "directed.h"
using namespace std;

struct Adjacency
{
    set<int> vertices;
};
void DFS_TopologicalSort(vector<Adjacency> &G, vector<bool> &visited, stack<int> &topologicalList, int vertex)
{
    visited[vertex] = true;
    for (int neighbor : G[vertex].vertices)
    {
        if (!visited[neighbor])
        {
            DFS_TopologicalSort(G, visited, topologicalList, neighbor);
        }
    }
    topologicalList.push(vertex);
}
void DFS_Kosaraju(vector<Adjacency> &G, vector<bool> &visited, int vertex)
{
    cout << vertex << endl;
    visited[vertex] = true;
    for (int neighbor : G[vertex].vertices)
    {
        if (!visited[neighbor])
        {
            DFS_Kosaraju(G, visited, neighbor);
        }
    }
}
int main()
{
    io;
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);

    int N, M;
    cin >> N >> M;
    vector<Adjacency> G(N + 1);
    vector<Adjacency> transposeG(N + 1);
    vector<bool> visited(N + 1, false);
    int stronglyconnectedComponent = 0;

    int startVertex, endVertex;
    for (int i = 0; i < M; i++)
    {
        cin >> startVertex >> endVertex;
        G[startVertex].vertices.insert(endVertex);
        transposeG[endVertex].vertices.insert(startVertex);
    }

    stack<int> topologicalList;
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            DFS_TopologicalSort(G, visited, topologicalList, i);
        }
    }
    FILL(visited, false);
    while (!topologicalList.empty())
    {
        int vertex = topologicalList.top();
        topologicalList.pop();
        if (!visited[vertex])
        {
            DFS_Kosaraju(transposeG, visited, vertex);
            stronglyconnectedComponent++;
            cout << endl;
        }
    }
    //! CAN'T DO THIS!!!
    // for (int vertex = 1; vertex <= N; vertex++)
    // {
    //     if (!visited[vertex])
    //     {
    //         DFS_Kosaraju(transposeG, visited, vertex);
    //         stronglyconnectedComponent++;
    //         cout << endl;
    //     }
    // }
    cout << stronglyconnectedComponent;
    //! WHY USING STACK INSTEAD OF ARRAY?
    //! -
    return 0;
}
