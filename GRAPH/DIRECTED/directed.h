#pragma once
#pragma GCC optimize("O2")
#pragma warning(disable : 4996)

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using ld = long double;
using ll = long long;
using ull = unsigned long long;
using uli = unsigned long int;
using namespace std;

const bool BruteForce = false;

#define PI 3.141592653589793
#define INF 1000000000
#define MOD 1000000007
#define MAX 100001

#define io                        \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);
#define iint pair<int, int>
#define llong pair<long long, long long>
#define st first
#define nd second
#define input "Directed.in"
#define output "Directed.out"

#define MTY(Container) Container.empty()
#define SIZE(Container) (Container).size()
#define MEM(Array, value) memset(Array, value, sizeof(Array))
#define REV(Container) reverse(Container.begin(), Container.end())
#define FILL(Container, value) fill(Container.begin(), Container.end(), value)
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define FOREACH(i, Container) for (auto i = (Container).begin(); i != (Container).end(); ++i)
#define ALL(Container) (Container).begin(), (Container).end()
#define PUSHBACK(Container, value) Container.push_back(value)
#define PUSHFRONT(Container, value) Container.push_front(value)
#define POPBACK(Container, value) Container.pop_back(value)
#define POPFRONT(Container, value) Container.pop_front(value)
#define DEBUG cout << "SUCCESS!"
#define TLE cerr << "TLE: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";

int crash = 10001;
template <class dataType>
istream &operator>>(istream &in, vector<dataType> &Array)
{
    FOR(i, 0, Array.size())
    in >> Array[i];
    return in;
}
template <class dataType>
ostream &operator<<(ostream &out, vector<dataType> Array)
{
    FOR(i, 0, Array.size())
    out << Array[i] << " ";
    return out;
}
