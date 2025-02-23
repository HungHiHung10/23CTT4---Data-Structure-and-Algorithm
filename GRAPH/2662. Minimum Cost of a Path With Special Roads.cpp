#include "graph.h"
using namespace std;
class Solution
{
private:
    struct Point
    {
        int x;
        int y;
        bool operator==(const Point &other) const
        {
            return x == other.x && y == other.y;
        }
        bool operator<(const Point &other) const
        {
            if (x == other.x)
                return y < other.y;
            return x < other.x;
        }
        bool operator>(const Point &other) const
        {
            if (x == other.x)
                return y > other.y;
            return x > other.x;
        }
    };
    struct Line
    {
        Point A;
        Point B;
        bool operator==(const Line &other) const
        {
            return A == other.A && B == other.B;
        }
        bool operator<(const Line &other) const
        {
            if (A == other.A)
                return B < other.B;
            return A < other.A;
        }
        bool operator>(const Line &other) const
        {
            if (A == other.A)
                return B > other.B;
            return A > other.A;
        }
    };

public:
    using ll = long long;
#define oo LLONG_MAX
    int Dijkstra(vector<vector<pair<int, ll>>> G, int V)
    {
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        vector<ll> distance(V, oo);
        distance[0] = 0;
        pq.emplace(0, 0);

        while (!pq.empty())
        {
            auto [len, u] = pq.top();
            pq.pop();

            if (len > distance[u])
                continue;

            for (auto &[v, weight] : G[u])
            {
                if (distance[u] + weight < distance[v])
                {
                    distance[v] = distance[u] + weight;
                    pq.emplace(distance[v], v);
                }
            }
        }
        return distance[V - 1] == oo ? -1 : static_cast<int>(distance[V - 1]);
    }
    ll Manhattandistanceance(Point point1, Point point2)
    {
        int x1 = point1.x;
        int y1 = point1.y;
        int x2 = point2.x;
        int y2 = point2.y;
        return abs(x2 - x1) + abs(y2 - y1);
    }
    int minimumCost(vector<int> &start, vector<int> &target,
                    vector<vector<int>> &specialRoads)
    {
        set<Point> vertices;
        vertices.insert({{start[0], start[1]}});
        map<Line, ll> specials;
        for (const auto &road : specialRoads)
        {
            Point from = {road[0], road[1]};
            Point to = {road[2], road[3]};
            ll cost = road[4];
            vertices.insert(from);
            vertices.insert(to);
            if (specials[{from, to}])
            {
                specials[{from, to}] = min(specials[{from, to}], cost);
            }
            else
            {
                specials[{from, to}] = cost;
            }
        }
        vertices.insert({target[0], target[1]});
        int V = vertices.size();
        vector<vector<pair<int, ll>>> G(V);
        int i = 0;
        for (auto vertex1 = vertices.begin(); vertex1 != vertices.end();
             vertex1++, i++)
        {
            int j = 0;
            for (auto vertex2 = vertices.begin(); vertex2 != vertices.end();
                 vertex2++, j++)
            {
                if (*vertex1 == *vertex2)
                {
                    continue;
                }
                G[i].push_back({j, Manhattandistanceance(*vertex1, *vertex2)});
                if (specials[{*vertex1, *vertex2}])
                {
                    G[i].push_back({j, specials[{*vertex1, *vertex2}]});
                    specials[{*vertex1, *vertex2}] = 0;
                }
                if (specials[{*vertex2, *vertex1}])
                {
                    G[j].push_back({i, specials[{*vertex2, *vertex1}]});
                    specials[{*vertex2, *vertex1}] = 0;
                }
            }
        }
        return Dijkstra(G, V);
    }
};