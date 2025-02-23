// ĐỆ QUY
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

// 1. Tính tổng bình phương các số tự nhiên nhỏ hơn hoặc bằng n: S = 12+ 22+ ... + n2.
int sumOfSquares(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * n + sumOfSquares(n - 1);
}
// 2. Tìm ước chung lớn nhất của 2 số nguyên a, b:
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
// 3. Xác định một mảng có phải là đối xứng:
bool isPalindrome(int a[], int n, int diff = 0)
{
    if (diff > n / 2)
        return true;
    if (a[diff] != a[n - 1 - diff])
    {
        return false;
    }
    return isPalindrome(a, n, diff + 1);
}
// 4. Tính giai thừa cho một số:
int Factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * Factorial(n - 1);
}
// 5. Đếm số chữ số của một số nguyên:
int countDigit(int a)
{
    if (a < 0)
        return -a;
    if (a < 10)
        return 1;
    return 1 + countDigit(a / 10);
}
// 6. Số Fibonacci thứ n được tính như sau: F (n) = F (n −1) + F (n −2). Tìm số Fibonacci thứ n:
int FIB(int n)
{
    if (n <= 1)
        return n;
    return FIB(n - 1) + FIB(n - 2);
}
int main()
{
    io;
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
    return 0;
}