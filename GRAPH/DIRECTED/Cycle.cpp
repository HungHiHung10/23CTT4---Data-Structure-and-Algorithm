#include "directed.h"
using namespace std;

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
    bool DETECT_CYCLE(vector<Adjacency> listAdj, vector<char> &color, int vertex)
    {
        color[vertex] = 'G';
        for (int neighbor : listAdj[vertex].vertices)
        {
            if (color[neighbor] == 'W')
            {
                if (DETECT_CYCLE(listAdj, color, neighbor))
                    return true;
            }
            else if (color[neighbor] == 'G')
                return true;
        }
        color[vertex] = 'B';
        return false;
    }
};
int main()
{
    using namespace DepthFirstSearch_DFS;
    io;
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
    int N, M;
    cin >> N >> M;
    vector<Adjacency> listAdj(N + 1);
    vector<char> color(N + 1, 'W');

    int startVertex, endVertex;
    for (int i = 0; i < M; i++)
    {
        cin >> startVertex >> endVertex;
        listAdj[startVertex].vertices.insert(endVertex);
    }

    //* print Adjacency List
    for (int i = 1; i <= N; i++)
    {
        cout << "Vertex " << i << " -> ";
        for (auto iter = listAdj[i].vertices.begin(); iter != listAdj[i].vertices.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }

    for (int i = 1; i <= N; i++)
    {
        if (color[i] == 'W' && DepthFirstSearch_DFS::DETECT_CYCLE(listAdj, color, i))
        {
            cout << "TRUE!\n";
            return 0;
        }
    }
    cout << "FALSE!\n";
    return 0;
}