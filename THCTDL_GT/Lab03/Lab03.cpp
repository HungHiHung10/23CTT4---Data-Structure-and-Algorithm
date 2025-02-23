// BINARY SEARCH TREE
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

#define input "Lab03.in"
#define output "Lab03.out"
#define io                        \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

struct NODE
{
    int key;
    NODE *p_left;
    NODE *p_right;
};
// 1. Khởi tạo một NODE từ một giá trị cho trước :
NODE *createNode(int data)
{
    NODE *createNode = new NODE{data, nullptr, nullptr};
    return createNode;
}
// 2. Duyệt tiền thứ tự (Preorder Traversal):
void NLR(NODE *pRoot)
{
    if (pRoot == nullptr)
    {
        return;
    }
    cout << pRoot->key << " ";
    NLR(pRoot->p_left);
    NLR(pRoot->p_right);
}
// 3. Duyệt trung thứ tự (Inorder Traversal):
void LNR(NODE *pRoot)
{
    if (pRoot == nullptr)
    {
        return;
    }
    LNR(pRoot->p_left);
    cout << pRoot->key << " ";
    LNR(pRoot->p_right);
}
// 4. Duyệt hậu thứ tự (Postorder Traversal):
void LRN(NODE *pRoot)
{
    if (pRoot == nullptr)
    {
        return;
    }
    LRN(pRoot->p_left);
    LRN(pRoot->p_right);
    cout << pRoot->key << " ";
}
// 5. Duyệt theo mức :
void LevelOrder(NODE *pRoot)
{
    if (pRoot == nullptr)
    {
        return;
    }
    queue<NODE *> level;
    level.push(pRoot);
    while (!level.empty())
    {
        NODE *traversal = level.front();
        level.pop();
        if (traversal != nullptr)
        {
            cout << traversal->key << " ";
            if (traversal->p_left != nullptr)
            {
                level.push(traversal->p_left);
            }
            if (traversal->p_right != nullptr)
            {
                level.push(traversal->p_right);
            }
        }
    }
}
// 6. Tìm và trả về một NODE với giá trị cho trước từ một cây nhị phân tìm kiếm :
NODE *Search(NODE *pRoot, int x)
{
    if (pRoot == nullptr)
    {
        return nullptr;
    }
    if (pRoot->key == x)
    {
        return pRoot;
    }
    else if (pRoot->key > x)
    {
        return Search(pRoot->p_left, x);
    }
    else
    {
        return Search(pRoot->p_right, x);
    }
}
// 7. Thêm một NODE với giá trị cho trước vào cây nhị phân tìm kiếm :
void Insert(NODE *&pRoot, int x)
{
    if (pRoot == nullptr)
    {
        pRoot = createNode(x);
        return;
    }
    if (pRoot->key == x)
    {
        return;
    }
    else if (pRoot->key > x)
    {
        Insert(pRoot->p_left, x);
    }
    else
    {
        Insert(pRoot->p_right, x);
    }
}
// 8. Xoá một NODE với giá trị cho trước từ một cây nhị phân tìm kiếm :
void Remove(NODE *&pRoot, int x)
{
    if (pRoot == nullptr)
    {
        return;
    }
    if (pRoot->key > x)
    {
        Remove(pRoot->p_left, x);
    }
    else if (pRoot->key < x)
    {
        Remove(pRoot->p_right, x);
    }
    else
    {
        // Leaf NODE
        if (pRoot->p_left == nullptr && pRoot->p_right == nullptr)
        {
            delete pRoot;
            pRoot = nullptr;
            return;
        }
        // Single One(1) Left Child NODE
        else if (pRoot->p_left != nullptr && pRoot->p_right == nullptr)
        {
            NODE *temporaryNode = pRoot;
            pRoot = pRoot->p_left;
            // Nếu tôi chưa hiểu đoạn này
            delete temporaryNode;
            temporaryNode = nullptr;
            return;
        }
        // Single One(1) Right Child NODE
        else if (pRoot->p_left == nullptr && pRoot->p_right != nullptr)
        {
            NODE *temporaryNode = pRoot;
            pRoot = pRoot->p_right;
            delete temporaryNode;
            temporaryNode = nullptr;
            return;
        }
        // Both Two(2) Child NODE
        // 2 Ways:
        else
        {
            if (true)
            {
                // Step 1: Find the node with the minimum value in the right subtree.
                NODE *minNode = pRoot->p_right;
                while (minNode->p_left != nullptr)
                {
                    minNode = minNode->p_left;
                }
                // Step 2: Copy the value of the minimum node found in the right subtree to the node that needs to be removed.
                pRoot->key = minNode->key;
                // Step 3: Recursively remove the node that holds the duplicate value (the node we just copied from) in the right subtree.
                Remove(pRoot->p_right, minNode->key);
            }
            else
            {
                NODE *maxNode = pRoot->p_left;
                while (maxNode->p_right != nullptr)
                {
                    maxNode = maxNode->p_right;
                }
                pRoot->key = maxNode->key;
                Remove(pRoot->p_left, maxNode->key);
            }
        }
    }
}
// 9. Khởi tạo một cây nhị phân tìm kiếm từ một mảng cho trước :
NODE *createTree(int a[], int n)
{
    NODE *BST = nullptr;
    for (int i = 0; i < n; i++)
    {
        Insert(BST, a[i]);
    }
    return BST;
}
// 10. Xóa hoàn toàn một cây nhị phân tìm kiếm :
void removeTree(NODE *&pRoot)
{
    if (pRoot == nullptr)
    {
        return;
    }
    NODE *removeNode = pRoot;
    removeTree(pRoot->p_left);
    removeTree(pRoot->p_right);
    delete removeNode;
    removeNode = nullptr;
}
// 11. Tính chiều cao của một cây nhị phân tìm kiếm :
int Height(NODE *pRoot)
{
    if (pRoot == nullptr)
    {
        return 0;
    }
    return 1 + max(Height(pRoot->p_left), Height(pRoot->p_right));
}
// 12. Đếm số lượng NODE của một cây nhị phân :
int countNode(NODE *pRoot)
{
    if (pRoot == nullptr)
    {
        return 0;
    }
    return 1 + countNode(pRoot->p_left) + countNode(pRoot->p_right);
}
//  13. Tính tổng giá trị của toàn bộ NODEs trong một cây nhị phân :
int sumNode(NODE *pRoot)
{
    if (pRoot == nullptr)
    {
        return 0;
    }
    return pRoot->key + sumNode(pRoot->p_left) + sumNode(pRoot->p_right);
}
// 14. Tính toán chiều cao của một NODE với giá trị cho trước : (trả về -1 nếu không tồn tại)
int heightNode(NODE *pRoot, int value)
{
    if (pRoot == nullptr)
    {
        return -1;
    }
    if (pRoot->key == value)
    {
        return Height(pRoot);
    }
    else if (pRoot->key > value)
    {
        return heightNode(pRoot->p_left, value);
    }
    else
    {
        return heightNode(pRoot->p_right, value);
    }
}
// 15. * Tính toán tầng của một NODE cho trước :
int Level(NODE *pRoot, NODE *p)
{
    if (pRoot == nullptr)
    {
        return -1;
    }
    if (pRoot == p)
    {
        return 1;
    }
    else if (pRoot->key > p->key)
    {
        return 1 + Level(pRoot->p_left, p);
    }
    else
    {
        return 1 + Level(pRoot->p_right, p);
    }
}
// 16. * Đếm số lá của một cây nhị phân :
int countLeaf(NODE *pRoot)
{
    if (pRoot == nullptr)
    {
        return 0;
    }
    if (pRoot->p_left == nullptr && pRoot->p_right == nullptr)
    {
        // cout << "Leaf NODE: " << pRoot->key << endl;
        return 1;
    }
    return countLeaf(pRoot->p_left) + countLeaf(pRoot->p_right);
}
// 17. * Đếm số NODE của một cây nhị phân tìm kiếm mà giá trị key nhỏ hơn giá trị cho trước :
int countLess(NODE *pRoot, int x)
{
    if (pRoot == nullptr)
    {
        return 0;
    }
    if (pRoot->key < x)
    {
        // cout << "Less NODE: " << pRoot->key << endl;
        return 1 + countLess(pRoot->p_left, x) + countLess(pRoot->p_right, x);
    }
    else
    {
        return countLess(pRoot->p_left, x);
    }
}
// 18. * Đếm số lượng NODE của một cây nhị phân tìm kiếm cho trước mà giá trị key lớn hơn giá trị cho trước :
int countGreater(NODE *pRoot, int x)
{
    if (pRoot == nullptr)
    {
        return 0;
    }
    if (pRoot->key > x)
    {
        // cout << "Greater NODE: " << pRoot->key << endl;
        return 1 + countGreater(pRoot->p_left, x) + countGreater(pRoot->p_right, x);
    }
    else
    {
        return countGreater(pRoot->p_right, x);
    }
}
int maxKey(NODE *pRoot)
{
    if (pRoot == nullptr)
    {
        return INT_MIN;
    }
    return max({pRoot->key, pRoot->p_left->key, pRoot->p_right->key});
}
int minKey(NODE *pRoot)
{
    if (pRoot == nullptr)
    {
        return INT_MAX;
    }
    return min({pRoot->key, pRoot->p_left->key, pRoot->p_right->key});
}
// 19. * Xác định cây nhị phân có phải là cây nhị phân tìm kiếm hay không :
bool isBST(NODE *pRoot)
{
    if (pRoot == nullptr)
    {
        return true;
    }
    if (pRoot->key <= maxKey(pRoot->p_left) || pRoot->key >= minKey(pRoot->p_right))
    {
        return false;
    }
    if ((pRoot->p_left != nullptr && pRoot->p_left->key >= pRoot->key) || (pRoot->p_left != nullptr && pRoot->p_right->key <= pRoot->key))
    {
        return false;
    }
    return isBST(pRoot->p_left) && isBST(pRoot->p_right);
}
// 20. * Xác định cây nhị phân có phải là cây nhị phân tìm kiếm đầy đủ hay không :
bool isFullBST(NODE *pRoot)
{
    if (pRoot == nullptr)
    {
        return true;
    }
    if (isBST(pRoot) == false)
    {
        return false;
    }
    if (!((pRoot->p_left == nullptr && pRoot->p_right == nullptr) ||
          (pRoot->p_left != nullptr && pRoot->p_left->key < pRoot->key &&
           pRoot->p_right != nullptr && pRoot->p_right->key > pRoot->key)))
    {
        return false;
    }
    return isFullBST(pRoot->p_left) && isFullBST(pRoot->p_right);
}
int main()
{
    io;
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
    return 0;
}