#include <iostream>
#include <fstream>
#include <vector>
#define Input "MST.txt"
#define Output "Lab06.out"
#define p 1000000009
using namespace std;
struct Company
{
    string name;
    string profit_tax;
    string address;
    vector<Company> list;
};
// 1. Hàm đọc dữ liệu từ tập tin :
// • vector<Company> ReadCompanyList(string file_name)
// • Input : file_name là tên tập tin Input(ở bài tập thực hành này là Tập tin "MST.txt").
// • Output : danh sách các công ty đọc từ tập tin, được lưu vào biến có kiểu dữ liệu vector<Company>.
vector<Company> ReadCompanyList(string file_name)
{
    freopen(Input, "r", stdin);
    string firstLine;
    getline(cin, firstLine);

    vector<Company> company;
    string Name, Profit, Address;
    while (getline(cin, Name))
    {
        getline(cin, Profit);
        getline(cin, Address);
        company.push_back({Name, Profit, Address});
    }
    return company;
}
long long power(long long x, long long n, long long MOD)
{
    long long exp = 1LL;
    while (n)
    {
        if (n & 1)
        {
            exp = (exp % MOD * x % MOD) % MOD;
        }
        x = (x % MOD * x % MOD) % MOD;
        n >>= 1;
    }
    return exp;
}
// 2. Hàm băm một chuỗi(với chuỗi là tên của công ty) :
// • long long HashString(string company_name)
// • Input : company_name có kiểu dữ liệu string, là tên của chuỗi(tên công ty) cần băm.
// • Output : Kết quả của chuỗi sau khi băm, là một số nguyên có kiểu dữ liệu long long.
long long HashString(string company_name)
{
    long long hash = 0LL;
    int sz = company_name.size();
    if (sz < 20)
    {
        int i = 0;
        for (char chr : company_name)
        {
            hash = (hash % p + ((int)chr % p * power(31, i++, p)) % p) % p;
        }
    }
    else
    {
        for (int i = sz - 20; i < sz; i++)
        {
            hash = (hash % p + company_name[i] % p * power(31, i - (sz - 20), p) % p) % p;
        }
    }
    return hash;
}
// 3. Hàm tạo một bảng băm từ danh sách các công ty, có kích thước là 200 :
// • Company *CreateHashTable(vector<Company> list_company)
// • Input : list_company là danh sách các công ty đã được đọc từ tập tin.
// • Output : bảng băm được tạo từ danh sách Input.
// • Gợi ý : sử dụng hàm HashString đã được định nghĩa ở trên.
Company *CreateHashTable(vector<Company> list_company)
{
    Company *hashTable = new Company[20];
    for (Company company : list_company)
    {
        int index = HashString(company.name) % 20;
        hashTable[index].list.push_back(company);
    }
    return hashTable;
}
// 4. Hàm thêm thông tin 1 công ty vào bảng băm đã có :
// • void Insert(Company *hash_table, Company company)
// • Input : -hash_table : bảng băm hiện tại.- company là công ty muốn thêm vào bảng băm.
void Insert(Company *&hash_table, Company company)
{
    int index = HashString(company.name) % 20;
    hash_table[index].list.push_back(company);
}
// 5. Hàm tìm kiếm thông tin của 1 công ty trong bảng băm thông qua tên công ty :
// • Company *Search(Company *hash_table, string company_name)
// • Input : -hash_table là bảng băm(được lưu trong mảng).- company_name là tên công ty muốn tìm kiếm thông tin.
// • Ouput : công ty tìm được từ bảng băm, có kiểu dữ liệu Company.Trả về NULL nếu không tìm thấy công ty.
bool Search(Company *hash_table, string company_name)
{
    int index = HashString(company_name) % 20;
    for (Company company : hash_table[index].list)
    {
        if (company.name == company_name)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    vector<Company> company = ReadCompanyList(Input);
    freopen(Output, "w", stdout);
    for (auto c : company)
    {
        cout << c.name << " | " << c.address << " | " << c.profit_tax << endl;
    }
    return 0;
}