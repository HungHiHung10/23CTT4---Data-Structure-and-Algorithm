//! https://wiki.vnoi.info/algo/graph-theory/topological-sort.md
//! https://www.geeksforgeeks.org/topological-sorting/
//* THERE IS CERTAINTLY NO CYCLE!!!
#include "directed.h"
using namespace std;

struct Adjacency
{
    set<int> vertices;
};
bool detectCycle(vector<Adjacency> listAdj, vector<char> &color, int vertex)
{
    color[vertex] = 'G';
    for (int neighbor : listAdj[vertex].vertices)
    {
        if (color[neighbor] == 'W')
        {
            if (detectCycle(listAdj, color, neighbor))
                return true;
        }
        else if (color[neighbor] == 'G')
        {
            return true;
        }
    }
    color[vertex] = 'B';
    return false;
}
stack<int> topologicalList;
//* DFS
void DFS(vector<Adjacency> listAdj, vector<bool> &visited, int vertex)
{
    visited[vertex] = true;
    for (int neighbor : listAdj[vertex].vertices)
    {
        if (!visited[neighbor])
        {
            DFS(listAdj, visited, neighbor);
        }
    }
    topologicalList.push(vertex);
}
//* Kahn Algorithm ~ BFS
int main()
{
    io;
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);

    int N, M;
    cin >> N >> M;
    vector<Adjacency> listAdj(N + 1);
    vector<bool> visited(N + 1, false);
    vector<char> color(N + 1, 'W');

    int startVertex, endVertex;
    for (int i = 0; i < M; i++)
    {
        cin >> startVertex >> endVertex;
        listAdj[startVertex].vertices.insert(endVertex);
    }
    // Detect if cycle in Directed Graph
    for (int i = 1; i <= N; i++)
    {
        if (color[i] == 'W' && detectCycle(listAdj, color, i))
        {
            cout << "IMPOSSIBLE!\n";
            return 0;
        }
    }
    // Construct Topological (sorted) List
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            DFS(listAdj, visited, i);
        }
    }

    while (!topologicalList.empty())
    {
        cout << topologicalList.top() << " ";
        topologicalList.pop();
    }

    //! NOTICE:
    //! There can be MULTIPLE valid Topological sortings.
    return 0;
}