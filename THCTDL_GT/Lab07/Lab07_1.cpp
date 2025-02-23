//! https://leetcode.com/problems/all-paths-from-source-to-target/description/
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <utility>
#define Input "Lab07.in"
#define Output "Lab07.out"
using namespace std;
using namespace a_directed_acyclic_graph
{
    vector<vector<int>> pathOfBFS;
    void bfs(vector<vector<int>> & G, int N, int source, int destination)
    {
        queue<vector<int>> Q;
        Q.push({source});
        while (!Q.empty())
        {
            vector<int> path = Q.front();
            Q.pop();
            int vertex = path.back();
            for (int neighbor : G[vertex])
            {
                vector<int> Path = path;
                Path.push_back(neighbor);
                if (neighbor == destination)
                {
                    pathOfBFS.push_back(Path);
                }
                else
                {
                    Q.push(Path);
                }
            }
        }
    }
    vector<vector<int>> pathOfDFS;
    void dfs(vector<vector<int>> & G, int N, int vertex, int source, int destination, vector<int> path)
    {
        path.push_back(vertex);
        if (vertex == destination)
        {
            pathOfDFS.push_back(path);
        }
        else
        {
            for (int neighbor : G[vertex])
            {
                dfs(G, neighbor, destination, path);
            }
        }
        path.pop_back();
    }
};
void BreadthFirstSearch(vector<vector<int>> &G, int N, int source, int destination)
{
    vector<int> parent(N, -1);
    vector<bool> visited(N, false);
    visited[source] = true;
    queue<int> Queue;
    Queue.push(source);
    while (!Queue.empty())
    {
        int vertex = Queue.front();
        Queue.pop();

        for (int neighbor : G[vertex])
        {
            if (!visited[neighbor])
            {
                parent[neighbor] = vertex;
                visited[neighbor] = true;
                Queue.push(neighbor);
            }
            if (neighbor == destination)
            {
                break;
            }
        }
    }
    for (int p : parent)
    {
        cout << p << " ";
    }
    cout << endl;
    // for (int vertex = destination; vertex != source; vertex = parent[vertex])
    // {
    //     cout << vertex << " ";
    // }
}
void DFS(vector<vector<int>> &G, int N, int vertex, int destination, vector<int> &parent, vector<bool> &visited)
{
    visited[vertex] = true;
    pathOfDFS.push_back(vertex);
    if (vertex == destination)
    {
        return;
    }
    for (int neighbor : G[vertex])
    {
        if (!visited[neighbor])
        {
            parent[neighbor] = vertex;
            DFS(G, N, neighbor, destination, parent, visited);
        }
    }
    pathOfDFS.pop_back();
}
void DepthFirstSearch(vector<vector<int>> &G, int N, int source, int destination)
{
    vector<int> parent(N, -1);
    vector<bool> visited(N, false);
    DFS(G, N, source, destination, parent, visited);
    for (int vertex = destination; vertex != source; vertex = parent[vertex])
    {
        cout << vertex << " ";
    }
}
int main()
{
    if (fopen(Input, "r"))
    {
        freopen(Input, "r", stdin);
        freopen(Output, "w", stdout);
    }
    else
    {
        cout << "error!";
    }
    int N, M, u, v;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int source = 0;
    int destination = 5;
    cout << "\n_____BFS_____\n";
    BreadthFirstSearch(G, N, source, destination);
    cout << "\n_____DFS_____\n";
    DepthFirstSearch(G, N, source, destination);
    return 0;
}
