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
void BFS(vector<Adjacency> listAdj, vector<bool> &visited)
{
    if (listAdj.size() == 0)
    {
        return;
    }
    queue<int> Queue;
    Queue.push(1);
    visited[1] = true;
    while (!Queue.empty())
    {
        int vertex = Queue.front();
        cout << vertex << " ";
        Queue.pop();
        for (int neighbor : listAdj[vertex].vertices)
        {
            if (!visited[neighbor])
            {
                Queue.push(neighbor);
                visited[neighbor] = true;
            }
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
    vector<Adjacency> listAdj(N + 1);
    vector<bool> visited(N + 1, false);

    int vertexU, vertexV;
    for (int i = 0; i < M; i++)
    {
        cin >> vertexU >> vertexV;
        listAdj[vertexU].vertices.insert(vertexV);
        listAdj[vertexV].vertices.insert(vertexU);
    }
    cout << "BFS: ";
    BFS(listAdj, visited);
    return 0;
}
//! NOTICE:
//* BFS cannot traverse ALL vertices in a Directed Graph on the first attempt if Directed Graph is not STRONG-CONNECTED!!!
//! https://lqdoj.edu.vn/problem/bfs
