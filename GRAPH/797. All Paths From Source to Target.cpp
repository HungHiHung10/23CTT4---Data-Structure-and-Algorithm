#include "graph.h"
using namespace std;
// _____DFS_____
// class Solution {
// public:
//     vector<vector<int>> res;
//     void DFS(vector<vector<int>>& G, int n, int vertex, vector<int>& path)
//     {
//         path.push_back(vertex);
//         for (int neighbor : G[vertex])
//         {
//             if (neighbor == n - 1)
//             {
//                 path.push_back(n - 1);
//                 res.push_back(path);
//                 path.pop_back();
//             }
//             DFS(G, n, neighbor, path);
//         }
//         path.pop_back();
//     }
//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int> path;
//         DFS(graph, n, 0, path);
//         return res;
//     }
// };
// Because of THE DIRECTED ACYCLIC GRAPH (DAG),
// _____BFS_____
class Solution
{
public:
    vector<vector<int>> res;
    void BFS(vector<vector<int>> &G, int n)
    {
        queue<vector<int>> Q;
        Q.push({0});

        while (!Q.empty())
        {
            vector<int> path = Q.front();
            Q.pop();
            int vertex = path.back();
            for (int neighbor : G[vertex])
            {
                vector<int> Path = path;
                Path.push_back(neighbor);
                if (neighbor == n - 1)
                {
                    res.push_back(Path);
                }
                Q.push(Path);
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        int n = graph.size();
        BFS(graph, n);
        return res;
    }
};