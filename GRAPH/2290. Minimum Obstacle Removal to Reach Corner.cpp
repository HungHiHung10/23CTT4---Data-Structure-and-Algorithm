//! 0.15% of solutions used 20 ms of runtime
// #define NO_SAN __attribute__((no_sanitize("undefined", "address", "coverage", "thread")))
// #define INL __attribute__((always_inline))
// #define HOT __attribute__((hot))
// #define INL_ATTR noexcept INL NO_SAN HOT
// #define OUTL_ATTR noexcept NO_SAN HOT

// template <class T, class S, S cap>
// struct ring_queue
// {
//     S start, end;
//     T elem[cap];

//     ring_queue() INL_ATTR : start(0), end(0) {}

//     void push(const T v) INL_ATTR
//     {
//         elem[end++] = v;
//         if (end >= cap)
//             end = 0;
//     }

//     T pop() INL_ATTR
//     {
//         const T r = elem[start++];
//         if (start >= cap)
//             start = 0;
//         return r;
//     }

//     bool empty() INL_ATTR
//     {
//         return start == end;
//     }
// };

// class Solution
// {
// public:
//     static int minimumObstacles(vector<vector<int>> &grid) OUTL_ATTR
//     {
//         const uint m = grid.size(), n = grid.front().size();
//         const uint8_t nord = 32 - countl_zero(n);
//         const uint cmask = (1u << nord) - 1u, endcoo = ((m - 1u) << nord) + n - 1u;
//         constexpr uint QCAP = 100'000;
//         ring_queue<uint, uint, QCAP> que[2];
//         que[0].push(0);
//         uint cost = 0;
//         bool a = false;
//         grid.front().front() = -1;

//         while (!que[a].empty())
//         {
//             while (!que[a].empty())
//             {
//                 const uint coo = que[a].pop();
//                 const uint i = coo >> nord, j = coo & cmask;
//                 if (int b = !!i, &g = grid[i - b][j]; b & g >= 0)
//                 {
//                     que[a ^ g].push(coo - cmask - 1u);
//                     g = -1;
//                 }
//                 if (int b = i + 1u < m, &g = grid[i + b][j]; b & g >= 0)
//                 {
//                     if (coo + cmask + 1u == endcoo) [[unlikely]]
//                         return cost + g;
//                     que[a ^ g].push(coo + cmask + 1u);
//                     g = -1;
//                 }
//                 if (int b = !!j, &g = grid[i][j - b]; b & g >= 0)
//                 {
//                     que[a ^ g].push(coo - 1u);
//                     g = -1;
//                 }
//                 if (int b = j + 1u < n, &g = grid[i][j + b]; b & g >= 0)
//                 {
//                     if (coo + 1u == endcoo) [[unlikely]]
//                         return cost + g;
//                     que[a ^ g].push(coo + 1u);
//                     g = -1;
//                 }
//             }
//             cost++;
//             a = !a;
//         }
//         return -1;
//     }
// };

// auto init = []()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return 'c';
// }();
#include "graph.h"
using namespace std;    
// //! Dijkstra Algorithm(Multidimensional) ~ O(m * n * log(m * n))
class Solution
{
private:
    vector<pair<int, int>> directions = {
        {-1, 0}, // up
        {0, 1},  // down
        {1, 0},  // left
        {0, -1}  // right
    };

public:
    using ll = long long;
    int Dijkstra(vector<vector<int>> &grid, int m, int n)
    {
        vector<vector<ll>> obstacle(m, vector<ll>(n, INT_MAX));
        obstacle[0][0] = grid[0][0];
        priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
        pq.emplace(grid[0][0], 0, 0);
        while (!pq.empty())
        {
            auto [barrier, start_x, start_y] = pq.top();
            pq.pop();

            if (obstacle[start_x][start_y] < barrier)
            {
                continue;
            }

            for (const auto &[directions_x, directions_y] : directions)
            {
                int move_x = start_x + directions_x;
                int move_y = start_y + directions_y;

                if (!(move_x >= 0 && move_x < m && move_y >= 0 && move_y < n))
                {
                    continue;
                }

                if (obstacle[start_x][start_y] + grid[move_x][move_y] < obstacle[move_x][move_y])
                {
                    obstacle[move_x][move_y] = obstacle[start_x][start_y] + grid[move_x][move_y];
                    pq.emplace(obstacle[move_x][move_y], move_x, move_y);
                }
            }
        }
        return obstacle[m - 1][n - 1];
    }
    int minimumObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        return Dijkstra(grid, m, n);
    }
};

// //! 0-1 Breadth-First-Search(BFS) ~ O(m * n)
class Solution
{
private:
    vector<pair<int, int>> directions = {
        {-1, 0}, // up
        {0, 1},  // down
        {1, 0},  // left
        {0, -1}  // right
    };

public:
    using ll = long long;
    int BFS(vector<vector<int>> &grid, int m, int n)
    {
        vector<vector<ll>> obstacle(m, vector<ll>(n, INT_MAX));
        obstacle[0][0] = grid[0][0];
        deque<tuple<int, int, int>> dq;
        dq.push_back({grid[0][0], 0, 0});

        while (!dq.empty())
        {
            auto [barrier, start_x, start_y] = dq.front();
            dq.pop_front();

            if (barrier > obstacle[start_x][start_y])
            {
                continue;
            }

            for (auto [direction_x, direction_y] : directions)
            {
                int move_x = start_x + direction_x;
                int move_y = start_y + direction_y;

                if (!(move_x >= 0 && move_x < m && move_y >= 0 && move_y < n))
                {
                    continue;
                }

                if (obstacle[start_x][start_y] + grid[move_x][move_y] < obstacle[move_x][move_y])
                {
                    obstacle[move_x][move_y] = obstacle[start_x][start_y] + grid[move_x][move_y];
                    if (grid[move_x][move_y] == 1)
                    {
                        dq.push_back({obstacle[move_x][move_y], move_x, move_y});
                    }
                    else
                    {
                        dq.push_front({obstacle[move_x][move_y], move_x, move_y});
                    }
                }
            }
        }
        return obstacle[m - 1][n - 1];
    }
    int minimumObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        return BFS(grid, m, n);
    }
};
// //! BackTracking ~ O(2^(m * n))
class Solution
{
private:
    vector<pair<int, int>> directions = {
        {-1, 0}, // up
        {0, 1},  // down
        {1, 0},  // left
        {0, -1}  // right
    };

public:
    int result = INT_MAX;
    void backTracking(vector<vector<int>> &grid, vector<vector<bool>> &visited, int end_x, int end_y, int start_x, int start_y, int obstacle)
    {
        visited[start_x][start_y] = true;
        if (start_x == end_x - 1 && start_y == end_y - 1)
        {
            result = min(result, obstacle);
        }
        else
        {
            for (const auto &[direction_x, direction_y] : directions)
            {
                int move_x = start_x + direction_x;
                int move_y = start_y + direction_y;
                if (move_x >= 0 && move_x < end_x &&
                    move_y >= 0 && move_y < end_y &&
                    visited[move_x][move_y] == false)
                {
                    backTracking(grid, visited, end_x, end_y, move_x, move_y, obstacle + (grid[move_x][move_y] == 1));
                }
            }
        }
        visited[start_x][start_y] = false;
    }
    int minimumObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        backTracking(grid, visited, m, n, 0, 0, (int)(grid[0][0] == 1));
        return result;
    }
};
