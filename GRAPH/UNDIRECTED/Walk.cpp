//* DFS ~ Find if there exists a path from starting-vertex to ending-vertex in Undirected Graph.
//* Example: count Connected Components; ...
//*BFS ~ Find the SHORTEST path from starting-vertex to ending-vertex in Undirected Graph.
#include "undirected.h"
struct Adjacency
{
    set<int> vertices;
};
struct Edge
{
    pair<int, int> edges;
};
namespace DepthFirstSearch_DFS
{
    bool FIND_PATH(vector<Adjacency> listAdj, vector<bool> &visited, int startVertex, int endVertex)
    {
        vector<int> parentTrace(listAdj.size() + 1, 0);
        stack<int> Stack;
        Stack.push(startVertex);
        visited[startVertex] = true;
        while (!Stack.empty())
        {
            int vertex = Stack.top();
            Stack.pop();
            if (vertex == endVertex)
            {
                vector<int> Path;
                Path.push_back(endVertex);
                for (int i = endVertex; i != startVertex; i = parentTrace[i])
                {
                    Path.push_back(parentTrace[i]);
                }
                REV(Path);
                cout << Path;
                return true;
            }
            for (int neighbor : listAdj[vertex].vertices)
            {
                if (!visited[neighbor])
                {
                    Stack.push(neighbor);
                    visited[neighbor] = true;
                    parentTrace[neighbor] = vertex;
                }
            }
        }

        return false;
    }
    bool DETECT_CYCLE(vector<Adjacency> listAdj, vector<bool> &visited)
    {
        vector<int> parentTrace(listAdj.size() + 1, 0);
        stack<int> Stack;
        Stack.push(1);
        visited[1] = true;
        while (!Stack.empty())
        {
            int vertex = Stack.top();
            Stack.pop();
            cout << vertex << " ";
            for (int neighbor : listAdj[vertex].vertices)
            {
                if (!visited[neighbor])
                {
                    Stack.push(neighbor);
                    visited[neighbor] = true;
                    parentTrace[neighbor] = vertex;
                }
                else
                {
                    if (parentTrace[vertex] != neighbor && listAdj[neighbor].vertices.find(vertex) != listAdj[neighbor].vertices.end())
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
namespace BreadthFirstSearch_BFS
{
    bool FIND_PATH(vector<Adjacency> listAdj, vector<bool> &visited, int startVertex, int endVertex)
    {
        vector<int> parentTrace(listAdj.size() + 1, 0);
        queue<int> Queue;
        Queue.push(startVertex);
        visited[startVertex] = true;
        while (!Queue.empty())
        {
            int vertex = Queue.front();
            Queue.pop();
            if (vertex == endVertex)
            {
                vector<int> Path;
                Path.push_back(endVertex);
                for (int i = endVertex; i != startVertex; i = parentTrace[i])
                {
                    Path.push_back(parentTrace[i]);
                }
                REV(Path);
                cout << Path;
                return true;
            }
            for (int neighbor : listAdj[vertex].vertices)
            {
                if (!visited[neighbor])
                {
                    Queue.push(neighbor);
                    visited[neighbor] = true;
                    parentTrace[neighbor] = vertex;
                }
            }
        }
        return false;
    }
    bool DETECT_CYCLE(vector<Adjacency> listAdj, vector<bool> &visited)
    {
        vector<int> parentTrace(listAdj.size() + 1, 0);
        queue<int> Queue;
        Queue.push(1);
        visited[1] = true;
        while (!Queue.empty())
        {
            int vertex = Queue.front();
            Queue.pop();
            for (int neighbor : listAdj[vertex].vertices)
            {
                if (!visited[neighbor])
                {
                    Queue.push(neighbor);
                    visited[neighbor] = true;
                    parentTrace[neighbor] = vertex;
                }
                else
                {
                    if (parentTrace[vertex] != neighbor)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
int main()
{
    using namespace DepthFirstSearch_DFS;
    using namespace BreadthFirstSearch_BFS;
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
        // listAdj[vertexV].vertices.insert(vertexU);
    }

    // if (DepthFirstSearch_DFS::FIND_PATH(listAdj, visited, 1, 2))
    // {
    //     cout << "FOUND!\n";
    // }
    // else
    // {
    //     cout << "NOT FOUND!\n";
    // }

    //* print Adjacency List
    // for (int i = 1; i <= N; i++)
    // {
    //     cout << "Vertex " << i << "-> ";
    //     for (auto iter = listAdj[i].vertices.begin(); iter != listAdj[i].vertices.end(); iter++)
    //     {
    //         cout << *iter << " ";
    //     }
    //     cout << endl;
    // }

    fill(visited.begin(), visited.end(), false);
    if (DepthFirstSearch_DFS::DETECT_CYCLE(listAdj, visited))
    {
        cout << "TRUE!\n";
    }
    else
    {
        cout << "FALSE!\n";
    }
    return 0;
}