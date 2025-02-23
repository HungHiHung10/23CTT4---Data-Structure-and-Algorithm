BFS Tìm đường đi NGẮN NHẤT 
DFS Xác định tính liên thông

Xác định thành phần liên thông Đồ thị không/vô hướng DFS.
Xác định thành phần liên thông MẠNH Đồ thị có/hữu hướng TopologicalSort(G + reverse_G) + DFS.
Xác định thành phần liên thông YẾU Đồ thị có/hữu hướng TopologicalSort(G) + DFS.

**Lưu ý**
    Duyệt DFS đối với Đồ thị có/hữu hướng từ 1 đến V thay vì duyệt 1 lần.

Directed Acyclic Graph(DAG) ~ Dynamic Programming(DP)

Strongly Connected Components ~ Compress(DSU - Disjoint Set Union)