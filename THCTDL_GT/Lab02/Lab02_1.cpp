// 1. LINKED LIST
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

#define input "Lab02.in"
#define output "Lab02.out"
#define io                        \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

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
// 1. Khởi tạo một NODE từ một số nguyên cho trước:
NODE *createNode(int data)
{
    NODE *newNode = new NODE{data, nullptr};
    return newNode;
}
// 2. Khởi tạo List từ một NODE cho trước:
List *createList(NODE *p_node)
{
    List *newList = new List{p_node, p_node};
    return newList;
}
// 3. Chèn một số nguyên vào đầu một List cho trước:
bool addHead(List *&L, int data)
{
    NODE *headNode = createNode(data);
    if (L == nullptr)
    {
        L = createList(headNode);
        return true;
    }
    headNode->p_next = L->p_head;
    L->p_head = headNode;
    return true;
}
// 4. Chèn một số nguyên vào cuối một List cho trước:
bool addTail(List *&L, int data)
{
    NODE *tailNode = createNode(data);
    if (L == nullptr)
    {
        L = createList(tailNode);
        return true;
    }
    L->p_tail->p_next = tailNode;
    L->p_tail = tailNode;
    return true;
}
// 5. Xóa NODE đầu tiên của một List cho trước:
void removeHead(List *&L)
{
    if (L == nullptr)
    {
        return;
    }
    if (L->p_head->p_next == nullptr)
    {
        NODE *removeNode = L->p_head;
        L->p_head = nullptr;
        L->p_tail = nullptr;
        delete removeNode;
        removeNode = nullptr;
        return;
    }
    NODE *removeNode = L->p_head;
    L->p_head = L->p_head->p_next;
    delete removeNode;
}
// 6. Xóa NODE cuối cùng của một List cho trước:
void removeTail(List *&L)
{
    if (L == nullptr)
    {
        return;
    }
    if (L->p_head->p_next == nullptr)
    {
        NODE *removeNode = L->p_head;
        L->p_head = nullptr;
        L->p_tail = nullptr;
        delete removeNode;
        removeNode = nullptr;
        return;
    }
    NODE *tempNode = L->p_head;
    while (tempNode->p_next->p_next != nullptr)
    {
        tempNode = tempNode->p_next;
    }
    tempNode->p_next = nullptr;
    NODE *removeNode = L->p_tail;
    L->p_tail = tempNode;
    delete removeNode;
    removeNode = nullptr;
    return;
}
// 7. Xóa tất cả các NODE của một List cho trước:
void removeAll(List *&L)
{
    if (L == nullptr)
    {
        return;
    }
    NODE *tempNode = L->p_head;
    while (tempNode != nullptr)
    {
        NODE *removeNode = tempNode;
        tempNode = tempNode->p_next;
        delete removeNode;
        removeNode = nullptr;
    }
    L->p_head = nullptr;
    L->p_tail = nullptr;
}
// 8. In tất cả phần tử của một List cho trước:
void printList(List *L)
{
    if (L == nullptr)
    {
        return;
    }
    NODE *tempNode = L->p_head;
    while (tempNode != nullptr)
    {
        cout << tempNode->key << "->";
        if (tempNode == L->p_tail)
            cout << " nullptr\n ";
        tempNode = tempNode->p_next;
    }
}
// 9. Đếm số lượng phần tử của một List cho trước:
int countElements(List *L)
{
    int count = 0;
    if (L == nullptr)
    {
        return count;
    }
    NODE *tempNode = L->p_head;
    while (tempNode != nullptr)
    {
        tempNode = tempNode->p_next;
        count++;
    }
    return count;
}
// 10. Đảo một List cho trước (tạo ra một List mới):
List *reverseList(List *L)
{
    List *revL = nullptr;
    NODE *tempNode = L->p_head;
    while (tempNode != nullptr)
    {
        addHead(revL, tempNode->key);
        tempNode = tempNode->p_next;
    }
    return revL;
}
// 11. Xóa tất cả các phần từ trùng của một List cho trước:
void removeDuplicate(List *&L)
{
    NODE *temp1 = L->p_head;
    while (temp1 != nullptr)
    {
        NODE *temp2 = temp1;
        while (temp2->p_next != nullptr)
        {
            if (temp2->p_next->key == temp1->key)
            {
                NODE *duplicateNode = temp2->p_next;
                if (duplicateNode == L->p_tail)
                {
                    removeTail(L);
                    continue;
                }
                temp2->p_next = temp2->p_next->p_next;
                delete duplicateNode;
                duplicateNode = nullptr;
            }
            else
            {
                temp2 = temp2->p_next;
            }
        }

        temp1 = temp1->p_next;
    }
}
// 12. Xóa giá trị key khỏi một List cho trước:
bool removeElement(List *&L, int key)
{
    if (L == nullptr)
    {
        return false;
    }
    if (L->p_head->key == key)
    {
        removeHead(L);
        return true;
    }
    if (L->p_tail->key == key)
    {
        removeTail(L);
        return true;
    }
    NODE *tempNode = L->p_head;
    while (tempNode->p_next != nullptr)
    {
        if (tempNode->p_next->key == key)
        {
            NODE *removeNode = tempNode->p_next;
            tempNode->p_next = tempNode->p_next->p_next;
            delete removeNode;
            removeNode = nullptr;
            return true;
        }
        tempNode = tempNode->p_next;
    }
    return false;
}
// 13. Chèn một số nguyên vào vị trí bất kì một List cho trước:
bool addPos(List *L, int data, int pos)
{
    if (L == nullptr)
    {
        return false;
    }
    if (!pos)
    {
        addHead(L, data);
        return true;
    }
    if (pos == countElements(L))
    {
        addTail(L, data);
        return true;
    }
    int index = 0;
    NODE *tempNode = L->p_head;
    NODE *addNode = createNode(data);
    while (tempNode->p_next != nullptr)
    {
        if (index++ == pos - 1)
        {
            addNode->p_next = tempNode->p_next;
            tempNode->p_next = addNode;
            return true;
        }
        tempNode = tempNode->p_next;
    }
    return false;
}
// 14. Xóa NODE ở vị trí bất kì của một List cho trước:
void removePos(List *L, int pos)
{
    if (L == nullptr)
    {
        return;
    }
    if (!pos)
    {
        removeHead(L);
        return;
    }
    if (pos == countElements(L) - 1)
    {
        removeTail(L);
        return;
    }
    int index = 0;
    NODE *tempNode = L->p_head;
    while (tempNode->p_next != nullptr)
    {
        if (index++ == pos - 1)
        {
            NODE *removeNode = tempNode->p_next;
            tempNode->p_next = tempNode->p_next->p_next;
            delete removeNode;
            removeNode = nullptr;
            return;
        }
        tempNode = tempNode->p_next;
    }
}
bool Ascending(int st, int nd)
{
    return st > nd;
}
bool Descending(int st, int nd)
{
    return st < nd;
}
void BubbleSort(List *&L, bool(compare)(int, int))
{
    if (L == nullptr || L->p_head == nullptr || L->p_head->p_next == nullptr)
        return;
    for (auto first = L->p_head; first->p_next != nullptr; first = first->p_next)
    {
        for (auto second = first->p_next; second != nullptr; second = second->p_next)
        {
            if (compare(first->key, second->key))
            {
                swap(first->key, second->key);
            }
        }
    }
}
// 15. Cho 2 List đã được sắp xếp tăng dần. Ghép 2 List lại thành một List mới được sắp xếp tăng dần.
List *ConcatList(List *L1, List *L2)
{
    NODE *temp1 = L1->p_head;
    NODE *temp2 = L2->p_head;
    List *L3 = nullptr;
    while (temp1 != nullptr && temp2 != nullptr)
    {
        if (temp1->key < temp2->key)
        {
            addTail(L3, temp1->key);
            temp1 = temp1->p_next;
        }
        else
        {
            addTail(L3, temp2->key);
            temp2 = temp2->p_next;
        }
    }
    while (temp1 != nullptr)
    {
        addTail(L3, temp1->key);
        temp1 = temp1->p_next;
    }
    while (temp2 != nullptr)
    {
        addTail(L3, temp2->key);
        temp2 = temp2->p_next;
    }
    return L3;
}
// 16. Cho 2 List đã được sắp xếp tăng dần. Ghép List 2 vào List 1 mà vẫn giữ sắp xếp tăng dần.
void MergeList(List *&L1, List *L2)
{
    if (L1 == nullptr)
    {
        L1 = L2;
        return;
    }
    if (L2 == nullptr)
    {
        return;
    }
    NODE *tempNode = L2->p_head;
    while (tempNode != nullptr)
    {
        addTail(L1, tempNode->key);
        tempNode = tempNode->p_next;
    }
    BubbleSort(L1, Ascending);
}
// 17. Xóa NODE ở vị trí chính giữa của List
void removeMiddle(List *&L)
{
    if (L == nullptr)
    {
        return;
    }
    if (L->p_head->p_next == nullptr)
    {
        delete L->p_head;
        L->p_head = nullptr;
        L = nullptr;
        return;
    }
    if (L->p_head->p_next->p_next == nullptr)
    {
        NODE *head = L->p_head;
        L->p_head = L->p_head->p_next;
        delete head;
        head = nullptr;
        return;
    }
    NODE *fast = L->p_head;
    NODE *prev = nullptr;
    NODE *slow = L->p_head;
    while (fast != nullptr && fast->p_next != nullptr)
    {
        fast = fast->p_next->p_next;
        prev = slow;
        slow = slow->p_next;
    }
    prev->p_next = prev->p_next->p_next;
    delete slow;
    slow = nullptr;
    return;
}
int main()
{
    io;
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
    return 0;
}