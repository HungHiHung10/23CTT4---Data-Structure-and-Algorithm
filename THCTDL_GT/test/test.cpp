//? 108. Convert Sorted Array to Binary Search Tree
// #include <iostream>
// #include <map>
// #include <unordered_map>
// #define input "input.txt"
// #define output "output.txt"
// #define io                        \
//     ios_base::sync_with_stdio(0); \
//     cin.tie(0);                   \
//     cout.tie(0);
// using namespace std;
// //* Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// //* Definition for a binary tree node.
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
// //* Contain height of binary tree node
// unordered_map<TreeNode *, int> height;
// int Height(TreeNode *node)
// {
//     if (node == nullptr)
//     {
//         return 0;
//     }
//     return height[node];
// }
// void rotateLeft(TreeNode *&x)
// {
//     TreeNode *y = x->right;
//     TreeNode *sub = y->left;

//     y->left = x;
//     x->right = sub;

//     height[x] = 1 + max(Height(x->left), Height(x->right));
//     height[y] = 1 + max(Height(y->left), Height(y->right));

//     x = y;
// }
// void rotateRight(TreeNode *&x)
// {
//     TreeNode *y = x->left;
//     TreeNode *sub = y->right;

//     y->right = x;
//     x->left = sub;

//     height[x] = 1 + max(Height(x->left), Height(x->right));
//     height[y] = 1 + max(Height(y->left), Height(y->right));

//     x = y;
// }
// void insertToBST(TreeNode *&root, int x)
// {
//     if (root == nullptr)
//     {
//         TreeNode *newNode = new TreeNode{x, nullptr, nullptr};
//         height[newNode] = 1;
//         root = newNode;
//         return;
//     }
//     if (root->val == x || root->val < x)
//     {
//         insertToBST(root->right, x);
//     }
//     else
//     {
//         insertToBST(root->left, x);
//     }
//     height[root] = 1 + max(Height(root->left), Height(root->right));
//     int balanceFactor = Height(root->left) - Height(root->right);
//     if (balanceFactor < -1 && x > root->right->val)
//     {
//         rotateLeft(root);
//     }
//     else if (balanceFactor > 1 && x < root->left->val)
//     {
//         rotateRight(root);
//     }
//     else if (balanceFactor > 1 && x > root->right->val)
//     {
//         rotateLeft(root->left);
//         rotateRight(root);
//     }
//     else if (balanceFactor < -1 && x < root->left->val)
//     {
//         rotateRight(root->right);
//         rotateLeft(root);
//     }
// }
// void printToArray(vector<int> nums)
// {
//     for (int value : nums)
//     {
//         cout << value << " ";
//     }
// }
// void printToBST(TreeNode *root)
// {
//     if (root == nullptr)
//     {
//         return;
//     }
//     cout << root->val << " ";
//     printToBST(root->left);
//     printToBST(root->right);
// }
// TreeNode *sortedArrayToBST(vector<int>& nums)
// {
//     TreeNode *root = nullptr;
//     for (int value : nums)
//     {
//         insertToBST(root, value);
//     }
//     return root;
// }
// void removeAllOfBST(TreeNode *&root)
// {
//     if (root == nullptr)
//     {
//         return;
//     }
//     TreeNode *removeNode = root;
//     removeAllOfBST(root->left);
//     removeAllOfBST(root->right);
//     delete removeNode;
//     removeNode = nullptr;
// }
// int main()
// {
//     io;
//     freopen(input, "r", stdin);
//     freopen(output, "w", stdout);
//     int n;
//     cin >> n;
//     vector<int> nums(n);
//     for (int& value : nums)
//     {
//         cin >> value;
//     }
//     printToArray(nums);
//     TreeNode *root = sortedArrayToBST(nums);
//     cout << "\nresult: ";
//     printToBST(root);
//     removeAllOfBST(root);
//     return 0;
// }
//? 109. Convert Sorted List to Binary Search Tree
// #include <iostream>
// #include <map>
// #include <unordered_map>
// #define input "input.txt"
// #define output "output.txt"
// #define io                        \
//     ios_base::sync_with_stdio(0); \
//     cin.tie(0);                   \
//     cout.tie(0);
// using namespace std;
// //* Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// //* Definition for a binary tree node.
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
// //* Contain height of binary tree node
// unordered_map<TreeNode *, int> height;
// // Haizz...😥
// void addToList(ListNode *&head, int value)
// {
//     ListNode *newNode = new ListNode{value, nullptr};
//     if (head == nullptr)
//     {
//         head = newNode;
//         return;
//     }
//     ListNode *move = head;
//     while (move->next != nullptr)
//     {
//         move = move->next;
//     }
//     move->next = newNode;
// }
// int Height(TreeNode *node)
// {
//     if (node == nullptr)
//     {
//         return 0;
//     }
//     return height[node];
// }
// void rotateLeft(TreeNode *&x)
// {
//     TreeNode *y = x->right;
//     TreeNode *sub = y->left;

//     y->left = x;
//     x->right = sub;

//     height[x] = 1 + max(Height(x->left), Height(x->right));
//     height[y] = 1 + max(Height(y->left), Height(y->right));

//     x = y;
// }
// void rotateRight(TreeNode *&x)
// {
//     TreeNode *y = x->left;
//     TreeNode *sub = y->right;

//     y->right = x;
//     x->left = sub;

//     height[x] = 1 + max(Height(x->left), Height(x->right));
//     height[y] = 1 + max(Height(y->left), Height(y->right));

//     x = y;
// }
// void insertToBST(TreeNode *&root, int x)
// {
//     if (root == nullptr)
//     {
//         TreeNode *newNode = new TreeNode{x, nullptr, nullptr};
//         height[newNode] = 1;
//         root = newNode;
//         return;
//     }
//     if (root->val == x || root->val < x)
//     {
//         insertToBST(root->right, x);
//     }
//     else
//     {
//         insertToBST(root->left, x);
//     }
//     height[root] = 1 + max(Height(root->left), Height(root->right));
//     int balanceFactor = Height(root->left) - Height(root->right);
//     if (balanceFactor < -1 && x > root->right->val)
//     {
//         rotateLeft(root);
//     }
//     else if (balanceFactor > 1 && x < root->left->val)
//     {
//         rotateRight(root);
//     }
//     else if (balanceFactor > 1 && x > root->right->val)
//     {
//         rotateLeft(root->left);
//         rotateRight(root);
//     }
//     else if (balanceFactor < -1 && x < root->left->val)
//     {
//         rotateRight(root->right);
//         rotateLeft(root);
//     }
// }
// void printToList(ListNode *head)
// {
//     cout << endl;
//     ListNode *move = head;
//     while (move != nullptr)
//     {
//         cout << move->val << " ";
//         move = move->next;
//     }
// }
// void printToBST(TreeNode *root)
// {
//     if (root == nullptr)
//     {
//         return;
//     }
//     cout << root->val << " ";
//     printToBST(root->left);
//     printToBST(root->right);
// }
// ListNode *removeTheMiddle(ListNode *&head)
// {
//     if (head == nullptr)
//     {
//         return nullptr;
//     }
//     if (head->next == nullptr)
//     {
//         ListNode *last = head;
//         head = nullptr;
//         return last;
//     }
//     if (head->next->next == nullptr)
//     {
//         ListNode *second = head;
//         head = head->next;
//         return second;
//     }
//     ListNode *fast = head;
//     ListNode *prev = nullptr;
//     ListNode *slow = head;
//     while (fast != nullptr && fast->next != nullptr)
//     {
//         fast = fast->next->next;
//         prev = slow;
//         slow = slow->next;
//     }
//     prev->next = prev->next->next;
//     return slow;
// }
// TreeNode *sortedListToBST(ListNode *&head)
// {
//     TreeNode *root = nullptr;
//     ListNode *move = head;
//     while (move != nullptr)
//     {
//         insertToBST(root, move->val);
//         move = move->next;
//     }
//     return root;
// }
// void deleteAllOfList(ListNode *&head)
// {
//     if (head == nullptr)
//     {
//         return;
//     }
//     ListNode *move = head;
//     while (move != nullptr)
//     {
//         ListNode *removeNode = move;
//         move = move->next;
//         delete removeNode;
//         removeNode = nullptr;
//     }
//     head = nullptr;
// }
// void removeAllOfBST(TreeNode *&root)
// {
//     if (root == nullptr)
//     {
//         return;
//     }
//     TreeNode *removeNode = root;
//     removeAllOfBST(root->left);
//     removeAllOfBST(root->right);
//     delete removeNode;
//     removeNode = nullptr;
// }
// int main()
// {
//     io;
//     freopen(input, "r", stdin);
//     freopen(output, "w", stdout);
//     int n, value;
//     cin >> n;
//     ListNode *head = nullptr;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> value;
//         addToList(head, value);
//     }
//     printToList(head);
//     TreeNode *root = sortedListToBST(head);
//     cout << "\nresult: ";
//     printToBST(root);
//     deleteAllOfList(head);
//     removeAllOfBST(root);
//     return 0;
// }
//? 61. Rotate List
// #include <iostream>
// #include <math.h>
// #define input "input.txt"
// #define output "output.txt"
// #define io                        \
//     ios_base::sync_with_stdio(0); \
//     cin.tie(0);                   \
//     cout.tie(0);
// using ll = long long;
// using namespace std;
// // Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// void addTail(ListNode *&head, int data)
// {
//     ListNode *add = new ListNode{data, nullptr};
//     if (head == nullptr)
//     {
//         head = add;
//         return;
//     }
//     ListNode *move = head;
//     while (move->next != nullptr)
//     {
//         move = move->next;
//     }
//     move->next = add;
// }
// int sizeList(ListNode *head)
// {
//     int size = 0;
//     ListNode *move = head;
//     while (move != nullptr)
//     {
//         size++;
//         move = move->next;
//     }
//     return size++;
// }
// ListNode *rotateRight(ListNode *head, int k)
// {
//     int size = sizeList(head);
//     if (size == 0 || size == 1 || k == 0 || k == size || k % size == 0)
//     {
//         return head;
//     }
//     // cout << "size: " << size << endl;
//     k = k % size;
//     // cout << "k: " << k << endl;
//     if (size == 0 || k == 0)
//     {
//         return head;
//     }
//     ListNode *move = head;
//     int pos = 1;
//     for (move; pos < (size - k); pos++)
//     {
//         move = move->next;
//     }
//     ListNode *half = move->next;
//     move->next = nullptr;
//     ListNode *shift = half;
//     while (shift != nullptr && shift->next != nullptr)
//     {
//         shift = shift->next;
//     }
//     shift->next = head;
//     return half;
// }
// void printList(ListNode *&head)
// {
//     if (head == nullptr)
//     {
//         return;
//     }
//     ListNode *move = head;
//     while (move != nullptr)
//     {
//         cout << move->val << " ";
//         move = move->next;
//     }
// }
// void removeAll(ListNode *&head)
// {
//     if (head == nullptr)
//     {
//         return;
//     }
//     ListNode *move = head;
//     while (move != nullptr)
//     {
//         ListNode *remove = move;
//         move = move->next;
//         delete remove;
//         remove = nullptr;
//     }
// }
// int main()
// {
//     cin.tie(0)->sync_with_stdio(0);
//     freopen(input, "r", stdin);
//     freopen(output, "w", stdout);

//     int n, k, value;
//     cin >> n >> k;
//     ListNode *head = nullptr;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> value;
//         addTail(head, value);
//     }
//     head = rotateRight(head, k);
//     printList(head);
//     removeAll(head);
//     return 0;
// }
//? 148. Sort List
#include <iostream>
using namespace std;
#define input "input.txt"
#define output "output.txt"
struct NODE
{
    int key;
    NODE *p_next;
};
struct List
{
    NODE *p_head;
    NODE *p_tail;
};
NODE *createNode(int value)
{
    NODE *newNode = new NODE{value, nullptr};
    return newNode;
}
void addHead(List *&L, int value)
{
    NODE *newNode = createNode(value);
    if (L == nullptr || L->p_head == nullptr)
    {
        L->p_head = L->p_tail = newNode;
        return;
    }
    newNode->p_next = L->p_head;
    L->p_head = newNode;
}
void addTail(List *&L, int value)
{
    NODE *newNode = createNode(value);
    if (L == nullptr || L->p_head == nullptr)
    {
        L->p_head = newNode;
        L->p_tail = newNode;
        return;
    }
    L->p_tail->p_next = newNode;
    L->p_tail = newNode;
}
NODE *split(NODE *&head)
{
    if (head == nullptr || head->p_next == nullptr)
    {
        return head;
    }
    NODE *fast = head;
    NODE *prev = nullptr;
    NODE *slow = head;
    while (fast != nullptr && fast->p_next != nullptr)
    {
        fast = fast->p_next->p_next;
        prev = slow;
        slow = slow->p_next;
    }
    prev->p_next = nullptr;
    return slow;
}
NODE *merge(NODE *head1, NODE *head2)
{
    if (head1 == nullptr)
    {
        return head2;
    }
    if (head2 == nullptr)
    {
        return head1;
    }
    if (head1->key < head2->key)
    {
        head1->p_next = merge(head1->p_next, head2);
        return head1;
    }
    else
    {
        head2->p_next = merge(head1, head2->p_next);
        return head2;
    }
}
NODE *mergeSort(NODE *head)
{
    if (head == nullptr || head->p_next == nullptr)
    {
        return head;
    }
    NODE *half = split(head);
    head = mergeSort(head);
    half = mergeSort(half);
    return merge(head, half);
}
void mergeSortList(List *&L)
{
    L->p_head = mergeSort(L->p_head);
    if (L->p_head == nullptr)
    {
        return;
    }
    NODE *moveNode = L->p_head;
    while (moveNode->p_next != nullptr)
    {
        moveNode = moveNode->p_next;
    }
    L->p_tail = moveNode;
}
int printList(List *&L)
{
    int size = 0;
    if (L == nullptr || L->p_head == nullptr)
    {
        return size;
    }
    NODE *moveNode = L->p_head;
    while (moveNode != nullptr)
    {
        cout << moveNode->key;
        if (moveNode != L->p_tail)
        {
            cout << "->";
        }
        moveNode = moveNode->p_next;
        size++;
    }
    return size;
}
void removeAll(List *&L)
{
    if (L == nullptr || L->p_head == nullptr)
    {
        return;
    }
    NODE *moveNode = L->p_head;
    while (moveNode != nullptr)
    {
        NODE *deleteNode = moveNode;
        moveNode = moveNode->p_next;
        delete deleteNode;
        deleteNode = nullptr;
    }
    L = nullptr;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
    int n, value;
    cin >> n;
    List *L = new List{nullptr, nullptr};
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        addTail(L, value);
    }
    printList(L);
    cout << endl;
    mergeSortList(L);
    cout << endl;
    printList(L);
    removeAll(L);
    return 0;
}