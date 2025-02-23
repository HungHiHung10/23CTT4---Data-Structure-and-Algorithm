// CON TRỎ
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

#define input "Lab01.in"
#define output "Lab01.out"
#define io                        \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

// 1. Viết hàm nhập vào một mảng số nguyên gồm n phần tử
void inputArray(int *a, int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> *(a + i);
    }
}
// 2. Viết hàm in các giá trị của mảng ra màn hình.
void printArray(int *a, int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << *(a + i) << " ";
    }
    cout << endl;
}
// 3. Viết hàm tìm giá trị nhỏ nhất trong mảng:
int FindMin(int *a, int n)
{
    int minValue = *(a);
    for (int i = 1; i < n; i++)
    {
        minValue = min(minValue, *(a + i));
    }
    return minValue;
}
// 4. Viết hàm tìm phần tử có trị tuyệt đối lớn nhất trong mảng:
int FindMaxModulus(int *a, int n)
{
    int maxAbs = *(a);
    for (int i = 1; i < n; i++)
    {
        if (abs(maxAbs) < abs(*(a + i)))
        {
            maxAbs = *(a + i);
        }
    }
    return maxAbs;
}
// 5. Viết hàm đếm số lần xuất hiện của giá trị bất kì trong mảng.
int countValue(int *a, int n, int key)
{
    int frequence = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(a + i) == key)
        {
            frequence++;
        }
    }
    return frequence;
}
// 6. Viết hàm đảo ngược chuỗi và in ra màn hình.
void StrRev(char *a)
{
    int size = strlen(a);
    char *b = new char[size];
    for (int i = 0; i < size; i++)
    {
        b[i] = a[size - 1 - i];
    }
    b[size] = '\0';
    a = b;
    cout << a << endl;
}
// 7. Viết hàm in hoa chữ cái đầu của từng từ và in ra màn hình. VD "Cau TRuC dU liEu" -> "Cau Truc Du Lieu".
void PrettyStr(char *a)
{
    if (strlen(a) == 0)
    {
        return;
    }
    a[0] = toupper(a[0]);
    for (int i = 1; i < strlen(a); i++)
    {
        if (a[i - 1] == ' ')
        {
            a[i] = toupper(a[i]);
        }
        else if (a[i - 1] != ' ' && a[i] != ' ')
        {
            a[i] = tolower(a[i]);
        }
    }
    cout << a << endl;
}
int main()
{
    io;
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
    return 0;
}