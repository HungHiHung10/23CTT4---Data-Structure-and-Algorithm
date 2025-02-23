#include "weighted.h"
using namespace std;

struct Adjacency
{
    set<int> vertices;
};
struct Edge
{
    pair<int, int> edges;
    int weighted;
};
namespace HEAP_SORT
{
    template <class dataType>
    void heapify(vector<dataType>& arr, int size, int index)
    {
        int leftChild = index * 2 + 1;
        int rightChild = index * 2 + 2;
        int largest = index;
        
        if (leftChild < size && arr[leftChild] > arr[largest])
        {
            largest = leftChild;
        }
        if (rightChild < size && arr[rightChild] > arr[largest])
        {
            largest = rightChild;
        }
        if (largest != index)
        {
            swap(arr[largest], arr[index]);
            heapify(arr, size, largest);
        }
    }
    template <class dataType>
    void heapSort(vector<dataType> &arr)
    {
        int size = arr.size();
        for (int i = size/2 - 1; i >= 0; i--)
        {
            heapify(arr, size, i);
        }
        for (int i = size - 1; i > 0; i--)
        {
            heapify(arr, i, 0);
        }
    }
}
namespace QUICK_SORT
{

}
namespace DSU
{
    struct Disjoint_Set_Union
    {
        vector<int> parent;
        vector<int> size;
    };
    
}
bool compareByWeighted(Edge A, Edge B)
{
    if (A.weighted == B.weighted)
    {
        if (A.edges.first == B.edges.first)
        {
            return A.edges.second < B.edges.second;
        }
        return A.edges.first < B.edges.second;
    }
    return A.weighted < B.weighted;
}
int main()
{
    using namespace DSU;
    using namespace HEAP_SORT;
    using namespace QUICK_SORT;
    io;
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);

    int N, M;
    cin >> N >> M;
    // vector<Adjacency> listA(N + 1);
    vector<Edge> listE(M);
    int vertexU, vertexV, weighted;
    for (int i = 0; i < M; i++)
    {
        cin >> vertexU >> vertexV >> weighted;
        // listA[vertexU].vertices.insert(vertexV);
        // listA[vertexV].vertices.insert(vertexU);
        listE[i].edges = make_pair(vertexU, vertexV);
        listE[i].weighted = weighted;
    }
    sort(listE.begin(), listE.end(), compareByWeighted);
    vector<int> parentTrace(N + 1);
    for (int i = 1; i <= N; i++)
    {
        parentTrace[i] = i;
    }

    return 0;
}