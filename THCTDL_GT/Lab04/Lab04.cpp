// AVL TREE
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

#define input "Lab04.in"
#define output "Lab04.out"
#define io                        \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

struct NODE
{
    int key;
    NODE *p_left;
    NODE *p_right;
    int height;
};
// 1. Khởi tạo một NODE từ một giá trị cho trước :
NODE *createNode(int data)
{
    NODE *createNode = new NODE{data, nullptr, nullptr, 1};
    return createNode;
}
int Height(NODE *Node)
{
    if (Node == nullptr)
    {
        return 0;
    }
    return Node->height;
}
void rotateLeft(NODE *&x)
{
    NODE *y = x->p_right;
    NODE *subTree = y->p_left;

    y->p_left = x;
    x->p_right = subTree;

    x->height = 1 + max(Height(x->p_left), Height(x->p_right));
    y->height = 1 + max(Height(y->p_left), Height(y->p_right));

    x = y;
}
void rotateRight(NODE *&x)
{
    NODE *y = x->p_left;
    NODE *subTree = y->p_right;

    y->p_right = x;
    x->p_left = subTree;

    x->height = 1 + max(Height(x->p_left), Height(x->p_right));
    y->height = 1 + max(Height(y->p_left), Height(y->p_right));

    x = y;
}
//! https://www.geeksforgeeks.org/insertion-in-an-avl-tree/
// 2. Thêm một NODE có giá trị cho trước vào cây AVL cho trước(Chú ý giá trị cho trước có tồn tại hay chưa) :
void Insert(NODE *&pRoot, int x)
{
    if (pRoot == nullptr)
    {
        NODE *insertNode = createNode(x);
        pRoot = insertNode;
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
    pRoot->height = 1 + max(Height(pRoot->p_left), Height(pRoot->p_right));
    int balanceFactor = (Height(pRoot->p_left) - Height(pRoot->p_right));
    //* Left - Left imbalance -> rotate Right at pRoot
    if (balanceFactor > 1 && x < pRoot->p_left->key)
    {
        rotateRight(pRoot);
        return;
    }
    //* Right - Right imbalance -> rotate Left at pRoot
    else if (balanceFactor < -1 && x > pRoot->p_right->key)
    {
        rotateLeft(pRoot);
        return;
    }
    //* Left - Right imbalance -> rotate Left at pRoot->p_left + rotate Right at pRoot
    else if (balanceFactor > 1 && x > pRoot->p_left->key)
    {
        rotateLeft(pRoot->p_left);
        rotateRight(pRoot);
        return;
    }
    //* Right - Left imbalance -> rotate Right at pRoot->p_right + rotate Left at pRoot
    else if (balanceFactor < -1 && x < pRoot->p_right->key)
    {
        rotateRight(pRoot->p_right);
        rotateLeft(pRoot);
    }
}
//! https://www.geeksforgeeks.org/deletion-in-an-avl-tree/
// 3. Xóa một NODE với giá trị cho trước từ một cây AVL cho trước(Chú ý giá trị đó có tồn tại hay không) :
void Remove(NODE *&pRoot, int x)
{
    if (pRoot == nullptr)
    {
        return;
    }
    if (pRoot->key == x)
    {
        if (pRoot->p_left == nullptr && pRoot->p_right == nullptr)
        {
            delete pRoot;
            pRoot = nullptr;
            return;
        }
        else if (pRoot->p_left == nullptr)
        {
            NODE *removeNode = pRoot;
            pRoot = pRoot->p_right;
            delete removeNode;
            removeNode = nullptr;
        }
        else if (pRoot->p_right == nullptr)
        {
            NODE *removeNode = pRoot;
            pRoot = pRoot->p_left;
            delete removeNode;
            removeNode = nullptr;
        }
        else
        {
            NODE *minNode = pRoot->p_right;
            while (minNode->p_left != nullptr)
            {
                minNode = minNode->p_left;
            }
            pRoot->key = minNode->key;
            Remove(pRoot->p_right, minNode->key);

            // OR
            // NODE *maxNode = pRoot->p_left;
            // while (maxNode->p_right != nullptr)
            // {
            //     maxNode = maxNode->p_right;
            // }
            // pRoot->key = maxNode->key;
            // Remove(pRoot->p_left, maxNode->key);
        }
    }
    else if (pRoot->key > x)
    {
        Remove(pRoot->p_left, x);
    }
    else
    {
        Remove(pRoot->p_right, x);
    }
    pRoot->height = 1 + max(Height(pRoot->p_left), Height(pRoot->p_right));
    int balanceFactor = (Height(pRoot->p_left) - Height(pRoot->p_right));
    if (balanceFactor < -1 && x > pRoot->p_right->key)
    {
        rotateLeft(pRoot);
    }
    else if (balanceFactor > 1 && x < pRoot->p_left->key)
    {
        rotateRight(pRoot);
    }
    else if (balanceFactor > 1 && x > pRoot->p_left->key)
    {
        rotateLeft(pRoot->p_left);
        rotateRight(pRoot);
    }
    else if (balanceFactor < -1 && x < pRoot->p_right->key)
    {
        rotateRight(pRoot->p_right);
        rotateLeft(pRoot);
    }
}
// 4. Duyệt tiền thứ tự(key và height của NODE được yêu cầu) :
void NLR(NODE *pRoot)
{
    if (pRoot == nullptr)
    {
        return;
    }
    cout << pRoot->key << "[" << pRoot->height << "]" << " ";
    NLR(pRoot->p_left);
    NLR(pRoot->p_right);
}
// 5. Duyệt trung thứ tự(key và height của NODE được yêu cầu) :
void LNR(NODE *pRoot)
{
    if (pRoot == nullptr)
    {
        return;
    }
    NLR(pRoot->p_left);
    cout << pRoot->key << "[" << pRoot->height << "]" << " ";
    NLR(pRoot->p_right);
}
//  6. Duyệt hậu thứ tự(key và height của NODE được yêu cầu) :
void LRN(NODE *pRoot)
{
    if (pRoot == nullptr)
    {
        return;
    }
    NLR(pRoot->p_left);
    NLR(pRoot->p_right);
    cout << pRoot->key << "[" << pRoot->height << "]" << " ";
}
//  7. Duyệt theo tầng(key và height của NODE được yêu cầu) :
void LevelOrder(NODE *pRoot)
{
    queue<NODE *> level;
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
// 8. * Xác định một cây nhị phân có phải là cây AVL không :
bool isAVL(NODE *pRoot)
{
    if (pRoot == nullptr)
    {
        return true;
    }
    int height_left = Height(pRoot->p_left);
    int height_right = Height(pRoot->p_right);
    if (abs(height_left - height_right) > 1)
    {
        return false;
    }
    return isAVL(pRoot->p_left) && isAVL(pRoot->p_right);
}
// 9. Xóa tất cả các NODE một cây AVL :
void Delete(NODE *&pRoot)
{
    if (pRoot == nullptr)
    {
        return;
    }
    NODE *T_left = pRoot->p_left;
    NODE *T_right = pRoot->p_right;
    delete pRoot;
    pRoot = nullptr;
    Delete(T_left);
    Delete(T_right);
}
// 10. Tìm và trả về một NODE với giá trị cho trước từ một cây AVL :
NODE *Search(NODE *&pRoot, int x)
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
int main()
{
    io;
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
    int n;
    cin >> n;
    NODE *AVL_T = nullptr;
    for (int i = 0; i < n; i++)
    {
        cout << i << " \n";
        Insert(AVL_T, i);
    }
    Remove(AVL_T, 4);
    NLR(AVL_T);
    cout << endl;
    LNR(AVL_T);
    cout << endl;
    LRN(AVL_T);
    cout << endl;
    Delete(AVL_T);
    return 0;
}