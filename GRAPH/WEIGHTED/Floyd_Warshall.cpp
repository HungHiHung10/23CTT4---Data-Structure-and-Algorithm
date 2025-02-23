#include <bits/stdc++.h>
#define input "LQDOJ10.in"
#define output "LQDOJ10.out"
using namespace std;
#define oo LLONG_MAX

int main()
{
    cin.tie(0)->sync_with_stdio(NULL);
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<long long>> Distance(n + 1, vector<long long>(n + 1, oo));

    // Khoảng cách từ một đỉnh đến chính nó là 0
    for (int i = 1; i <= n; i++)
        Distance[i][i] = 0;

    // Đọc cạnh
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Distance[a][b] = min(Distance[a][b], (long long)c);
        Distance[b][a] = min(Distance[b][a], (long long)c);
    }

    // Floyd-Warshall
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (Distance[i][k] < oo && Distance[k][j] < oo)
                {
                    Distance[i][j] = min(Distance[i][j], Distance[i][k] + Distance[k][j]);
                }
            }
        }
    }

    // Truy vấn
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (Distance[a][b] == oo)
            cout << -1 << endl; // Không có đường đi
        else
            cout << Distance[a][b] << endl;
    }

    return 0;
}
