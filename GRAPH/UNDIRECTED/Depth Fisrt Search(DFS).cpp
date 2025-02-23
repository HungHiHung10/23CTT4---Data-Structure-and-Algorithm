#include "undirected.h"
using namespace std;

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
void DFS(vector<Adjacency> listAdj, vector<bool> &visited)
{
    stack<int> Stack;
    Stack.push(1);
    visited[1] = true;
    while (!Stack.empty())
    {
        int vertex = Stack.top();
        cout << vertex << " ";
        Stack.pop();
        for (int neighbor : listAdj[vertex].vertices)
        {
            if (!visited[neighbor])
            {
                Stack.push(neighbor);
                visited[neighbor] = true;
            }
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
    vector<Adjacency> listAdj(N + 1);
    vector<bool> visited(N + 1, false);

    int vertexU, vertexV;
    for (int i = 0; i < M; i++)
    {
        cin >> vertexU >> vertexV;
        listAdj[vertexU].vertices.insert(vertexV);
        listAdj[vertexV].vertices.insert(vertexU);
    }

    cout << "DFS: ";
    DFS(listAdj, visited);
    return 0;
}
//! NOTICE:
//* DFS cannot traverse ALL vertices in a Directed Graph on the first attempt if Directed Graph is not STRONG-CONNECTED!!!
//! https://lqdoj.edu.vn/problem/dfs