// STRUCT
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

// 1. Viết chương trình nhập vào 2 mốc thời gian. Tính tổng thời gian và in ra màn hình.
struct time
{
    int hrs;
    int mins;
    int secs;
    friend time sumOf(time t_1, time t_2)
    {
        int s1 = t_1.hrs * 3600 + t_1.mins * 60 + t_1.secs;
        int s2 = t_2.hrs * 3600 + t_2.mins * 60 + t_2.secs;
        int s3 = s1 + s2;
        return {s3 / 3600, s3 % 3600 / 60, s3 % 3600 % 60};
    }
};
// 2. Viết chương tình cộng 2 phân số và in ra màn hình.
struct fraction
{
    int num;   // the numerator of the fraction
    int denom; // the denominator of the fraction
    friend fraction sumOf(fraction f_1, fraction f_2)
    {
        int numerator = f_1.num * f_2.denom + f_1.denom * f_2.num;
        int denominator = f_1.denom * f_2.denom;
        return {numerator, denominator};
    }
};
int main()
{
    io;
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
    return 0;
}
