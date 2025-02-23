// 2. STACK QUEUE
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
// #include <stack>
// #include <queue>
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
    NODE *pNext;
};
bool isEmpty(NODE *Container)
{
    return Container == nullptr;
}
void pushStack(NODE *&stack, int data)
{
    NODE *pushNode = new NODE{data, nullptr};
    if (stack == nullptr)
    {
        stack = pushNode;
        return;
    }
    pushNode->pNext = stack;
    stack = pushNode;
}
void popStack(NODE *&stack)
{
    if (stack == nullptr)
    {
        return;
    }
    if (stack->pNext == nullptr)
    {
        delete stack;
        stack = nullptr;
        return;
    }
    NODE *popNode = stack;
    stack = stack->pNext;
    delete popNode;
    popNode = nullptr;
}
int topStack(NODE *&stack)
{
    if (stack == nullptr)
    {
        return INT_MIN;
    }
    int topNode = stack->key;
    return topNode;
}
void pushQueue(NODE *&queue, int data)
{
    NODE *pushNode = new NODE{data, nullptr};
    if (queue == nullptr)
    {
        queue = pushNode;
        return;
    }
    NODE *shiftNode = queue;
    while (shiftNode->pNext != nullptr)
    {
        shiftNode = shiftNode->pNext;
    }
    shiftNode->pNext = pushNode;
}
void popQueue(NODE *&queue)
{
    if (queue == nullptr)
    {
        return;
    }
    if (queue->pNext == nullptr)
    {
        delete queue;
        queue = nullptr;
        return;
    }
    NODE *popNode = queue;
    queue = queue->pNext;
    delete popNode;
    popNode = nullptr;
}
int frontQueue(NODE *queue)
{
    if (queue == nullptr)
    {
        return INT_MIN;
    }
    // return queue->key;
    int frontNode = queue->key;
    return frontNode;
}
int backQueue(NODE *queue)
{
    if (queue == nullptr)
    {
        return INT_MIN;
    }
    NODE *shiftNode = queue;
    while (shiftNode != nullptr)
    {
        shiftNode = shiftNode->pNext;
    }
    // return shiftNode->key;
    int backNode = queue->key;
    return backNode;
}
// 1. Viết hàm đọc theo một chuỗi ký tự và in chúng theo thứ tự ngược lại. Sử dụng một ngăn xếp.
void ReverseString(const char *s)
{
    NODE *stack = nullptr;
    for (int i = 0; i < strlen(s); i++)
    {
        pushStack(stack, s[i]);
    }
    while (stack != nullptr)
    {
        cout << static_cast<char>(topStack(stack));
        popStack(stack);
    }
}
// 2. Viết chương trình đọc trong một chuỗi ký tự và xác định xem dấu ngoặc đơn (), dấu ngoặc nhọn {} và dấu ngoặc vuông [] của nó có "cân bằng" hay không.
void CheckBalance(const char *s)
{
    if (strlen(s) && (s[0] == ')' || s[0] == ']' || s[0] == '}'))
    {
        cout << "False";
        return;
    }
    NODE *stack = nullptr;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] < 'a' && s[i] > 'z' && s[i] < 'A' && s[i] > 'Z')
        {

            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                pushStack(stack, s[i]);
            }
            else {
                if (stack == nullptr)
                {
                    cout << "False";
                    return;
                }
                if ((s[i] == ')' && topStack(stack) != '(') ||
                    (s[i] == ']' && topStack(stack) != '[') ||
                    (s[i] == '}' && topStack(stack) != '{'))
                {
                    cout << "False";
                    return;
                }
                else
                {
                    popStack(stack);
                }
            }
        }
    }
    if (isEmpty(stack))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}
// 3. Viết chương trình đọc một số nguyên dương và in ra biểu diễn nhị phân của số nguyên đó VD:
void DecToBin(int dec)
{
    if (dec == 0)
    {
        cout << 0;
        return;
    }
    NODE *stack = nullptr;
    while (dec)
    {
        int bin = dec % 2;
        pushStack(stack, bin);
        dec /= 2;
    }
    while (stack != nullptr)
    {
        cout << topStack(stack);
        popStack(stack);
    }
}
int main()
{
    io;
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
    return 0;
}