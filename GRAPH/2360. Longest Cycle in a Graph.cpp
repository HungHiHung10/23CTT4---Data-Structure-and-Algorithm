#include "graph.h"
using namespace std;
class Solution
{
public:
    int res = -1;
    void DFS(vector<vector<int>> &G, vector<char> &color, vector<int> &length, int vertex)
    {
        color[vertex] = 'g';
        for (int neighbor : G[vertex])
        {
            if (color[neighbor] == 'w')
            {
                length[neighbor] = length[vertex] + 1;
                DFS(G, color, length, neighbor);
            }
            else if (color[neighbor] == 'g')
            {
                res = max(res, length[vertex] - length[neighbor] + 1);
            }
        }
        color[vertex] = 'b';
    }
    int longestCycle(vector<int> &edges)
    {
        int V = edges.size();
        vector<vector<int>> G(V);
        for (int i = 0; i < edges.size(); i++)
        {
            if (edges[i] >= 0)
                G[i] = {edges[i]};
        }
        vector<char> color(V, 'w');
        vector<int> length(V, 0);
        for (int i = 0; i < edges.size(); i++)
        {
            if (color[i] == 'w')
            {
                DFS(G, color, length, i);
            }
        }
        return res;
    }
};