#include "cycle.h"
using namespace std;
void Euler(vector<vector<int>>& G, int V, int E)
{
    stack<int> Stack;
    Stack.push(1);
    
}
int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> G(V + 1);
    int u, v;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        G[u].push_back(v);
    }
    Euler(G, V, E);
    return 0;
}