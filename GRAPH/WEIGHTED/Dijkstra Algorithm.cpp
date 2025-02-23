//! https://howkteam.vn/course/cau-truc-du-lieu-va-giai-thuat/tim-kiem-duong-di-ngan-nhat-tren-do-thi-dijikstra-4387
//! https://viblo.asia/p/thuat-toan-dijkstra-va-ung-dung-aWj53zgQl6m
//* Just applies only to non-negative weight graph
// O((V + E)⋅logV)
#include "weighted.h"
#define oo LLONG_MAX
using namespace std;

void Dijkstra(vector<vector<pair<int, int>>> &Graph, vector<bool> &marked, vector<long long> &distance, int source, int destination)
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> PQueue;
    distance[source] = 0LL;
    PQueue.push({0, source});
    while (!PQueue.empty())
    {
        pair<long long, int> Distance_Vertex = PQueue.top();
        // auto [length, vertex] = PQueue.top();
        PQueue.pop();
        if (marked[Distance_Vertex.second])
        {
            continue;
        }
        marked[Distance_Vertex.second] = true;
        for (auto neighbor : Graph[Distance_Vertex.second])
        {
            // for (auto [neighbor, weighted] : Graph[vertex])
            if (Distance_Vertex.first + neighbor.second < distance[neighbor.first])
            {
                distance[neighbor.first] = Distance_Vertex.first + neighbor.second;
                PQueue.push({Distance_Vertex.first + neighbor.second, neighbor.first});
            }
        }
    }
}
void Dijkstra(vector<vector<pair<int, int>>> &Graph, int N, int source, int destination)
{
    vector<long long> distance(N, oo);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> PQueue;
    PQueue.push({0LL, 1});
    distance[source] = 0;
    while (!PQueue.empty())
    {
        auto [length, vertex] = PQueue.top();
        PQueue.pop();
        if (length > distance[vertex])
        {
            continue;
        }
        for (auto [neighbor, weighted] : Graph[vertex])
        {
            if (distance[vertex] + weighted < distance[neighbor])
            {
                distance[neighbor] = distance[vertex] + weighted;
                PQueue.push({distance[neighbor], neighbor});
            }
        }
    }
    for (auto Distance : distance)
    {
        cout << Distance << " ";
    }
}
int main()
{
    io;
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);

    int N, M, u, v, w;
    cin >> N >> M;
    vector<vector<pair<int, int>>> Graph(N + 1);
    // vector<bool> visited(N + 1);
    vector<bool> marked(N + 1, false);
    vector<long long> distance(N + 1, oo);
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        Graph[u].push_back(make_pair(v, w));
    }
    for (int vertex = 1; vertex <= N; vertex++)
    {
        cout << vertex << " : \n";
        for (auto neighbor : Graph[vertex])
        {
            cout << '\t' << neighbor.first << " - " << neighbor.second << '\n';
        }
        cout << endl;
    }
    Dijkstra(Graph, marked, distance, 1, N);

    for (int i = 1; i <= N; i++)
    {
        cout << distance[i] << " ";
    }
    return 0;
}
//! https://lqdoj.edu.vn/problem/cses1671
//! https://lqdoj.edu.vn/problem/cses1672
//! https://lqdoj.edu.vn/problem/cses1195
//! https://lqdoj.edu.vn/problem/cses1202

// Đầu tiên, bài này có 1 bẫy mà rất dễ mắc phải đó chính là tìm đường đi ngắn nhất từ 1 đến n và tìm cạnh có trọng số lớn nhất trong đoạn đường đó.
// Tuy nhiên, cách làm này sẽ sai trong trường hợp mà tồn tại đường đi khác thỏa W(path1) > W(path2) nhưng W(path1) - w(uv) + w(uv)/2 < W(path2) - max_weight + (max_weight)/2.
// Do đó ta cần giải bài toán này như sau:
// Tìm đường đi ngắn nhất từ 1 đến n
// Ta cần tìm cạnh uv thuộc E(G) sao cho result = đường đi ngắn nhất(1->u) + uv/2 + đường đi ngắn nhẩt(v->n) là ngắn nhất thỏa.
// Vì ta không thể tìm đường đi(v->n) đối với mỗi một v -> TLE nên ta cần đảo chiều đồ thị thành revG và tìm đường đi ngắn nhất của revG từ n đến mọi đỉnh còn lại.
// Mặt khác, Đồ thị G có cạnh uv thì Đồ thị revG cũng có cạnh vu có trọng số không đỏi nên đường đi ngắn nhất từ W(v->n) == W(n->v).
