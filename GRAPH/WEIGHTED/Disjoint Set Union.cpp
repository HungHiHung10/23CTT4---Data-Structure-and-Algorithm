//! https://wiki.vnoi.info/algo/data-structures/disjoint-set-union
#include "weighted.h"
#define MAX_SIZE 1000005
using namespace std;

struct Disjoint_Set_Union
{
    int parent[MAX_SIZE] = {0};
};
int parent[MAX_SIZE] = {0};
//* Brute Force - Naive : O(MAX_SIZE)
void Set()
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        parent[i] = i;
    }
}
int Find(int V)
{
    if (V == parent[V])
    {
        return V;
    }
    return Find(parent[V]);
}
void Union(int X, int Y)
{
    X = Find(X);
    Y = Find(Y);
    if (X != Y)
    {
        parent[Y] = X;
    }
}

//* Optimization :
//* Path Compression Optimization
int Find_path_compression(int V)
{
    if (V == parent[V])
    {
        return V;
    }
    return parent[V] = Find_path_compression(V);
}
//* Optimization :
//* Merge by size/rank Optimization
int level[MAX_SIZE] = {0};
int rank[MAX_SIZE] = {0};
int Union_index_linking(int X, int Y)
{
    X = Find(X);
    Y = Find(Y);

    if (X != Y)
    {
        if (level[X] < level[Y])
        {
            swap(X, Y);
        }
        parent[Y] = X;
        if (level[X] == level[Y])
        {
            level[X]++;
        }
    }
}