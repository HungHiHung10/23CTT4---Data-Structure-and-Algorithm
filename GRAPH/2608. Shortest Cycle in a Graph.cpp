#include "graph.h"
using namespace std;
// DFS(Depth-First-Search) 82/88
// class Solution {
// public:
//     int res = INT_MAX;
//     void DFS(vector<vector<int>>& G, vector<char>& color, vector<int>& length, int vertex, int parent = -1)
//     {
//         color[vertex] = 'g';
//         for (int neighbor : G[vertex])
//         {
//             if (color[neighbor] == 'w')
//             {
//                 length[neighbor] = length[vertex] + 1;
//                 DFS(G, color, length, neighbor, vertex);
//             }
//             else if (color[neighbor] == 'g' && neighbor != parent)
//             {
//                 // cout << "vertex: " << vertex << " neighbor: " << neighbor << endl;
//                 // cout << "len[vertex]: " << length[vertex] << " len[neighbor]: " << length[neighbor] << endl;
//                 res = min(res, length[vertex] - length[neighbor] + 1);
//             }
//         }
//         color[vertex] = 'b';
//     }
//     int findShortestCycle(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> G(n);
//         for (vector<int> uv : edges)
//         {
//             int ui = uv[0];
//             int vi = uv[1];
//             G[ui].push_back(vi);
//             G[vi].push_back(ui);
//         }
//         for (int i = 0; i < n; i++)
//         {
//             sort(G[i].begin(), G[i].end());
//         }
//         vector<char> color(n, 'w');
//         vector<int> length(n, 0);
//         for (int i = 0; i < n; i++)
//         {
//             if (color[i] == 'w')
//             {
//                 DFS(G, color, length, i);
//             }
//         }
//         fill(color.begin(), color.end(), 'w');
//         fill(length.begin(), length.end(), 0);
//         for (int i = 0; i < n; i++)
//         {
//             sort(G[i].begin(), G[i].end(), greater<int>());
//         }
//         for (int i = 0; i < n; i++)
//         {
//             if (color[i] == 'w')
//             {
//                 DFS(G, color, length, i);
//             }
//         }
//         if (res == INT_MAX)
//         {
//             return -1;
//         }
//         return res;
//     }
// };

// BFS(Breadth-First-Search) 88/88
class Solution
{
public:
    int res = INT_MAX;
    void BFS(vector<vector<int>> &G, vector<bool> &visited, vector<int> &parent, vector<int> &length, int start)
    {
        queue<int> q;
        q.push(start);
        visited[start] = true;
        length[start] = 0;
        while (!q.empty())
        {
            int vertex = q.front();
            q.pop();

            for (int neighbor : G[vertex])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    length[neighbor] = length[vertex] + 1;
                    parent[neighbor] = vertex;
                    q.push(neighbor);
                }
                else if (parent[vertex] != neighbor)
                {
                    // cout << neighbor << " " << vertex << endl;
                    res = min(res, length[vertex] + length[neighbor] + 1);
                }
            }
        }
    }
    int findShortestCycle(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> G(n);
        for (vector<int> uv : edges)
        {
            int ui = uv[0];
            int vi = uv[1];
            G[ui].push_back(vi);
            G[vi].push_back(ui);
        }
        for (int i = 0; i < n; i++)
        {
            vector<bool> visited(n, false);
            vector<int> parent(n, -1);
            vector<int> length(n, 0);
            BFS(G, visited, parent, length, i);
        }
        if (res == INT_MAX)
        {
            return -1;
        }
        return res;
    }
};