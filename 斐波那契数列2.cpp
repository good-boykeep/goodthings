#include <iostream>
#include <windows.h>
using namespace std;
void NewFunction()
{
    SetConsoleOutputCP(65001);
}
long long fibonacci_nth(int n);
void fibonacci_sequence(int n);
long long fibonacci_sum(int n);

long long fibonacci_nth(int n)
{
    if (n <= 0)
        return n;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
void fibonacci_sequence(int n)
{
    if (n <= 0)
    {
        cout << "请输入大于零的整数" << endl;
        return;
    }
    cout << "斐波那契数列前" << n << "项；";
    if (n >= 1)
        cout << "1";
    if (n >= 2)
        cout << ",1";

    long long a = 0, b = 1;
    for (int i = 3; i <= n; i++)
    {
        long long c = a + b;
        cout << "," << c;
        a = b;
        b = c;
    }
    cout << endl;
}
long long fibonacci_sum(int n)
{
    if (n <= 0)
        return 0;
    long long sum = 0;
    long long a = 0, b = 1;

    sum += a;
    if (n == 0)
        return sum;
    for (int i = 1; i <= n; i++)
    {
        sum += b;
        long long next = a + b;
        a = b;
        b = next;
    }
    return sum;
}
int main()
{
    NewFunction();
    int n;
    cout << "请输入n的值:";
    cin >> n;
    long long nth = fibonacci_nth(n);
    cout << ")斐波那契数列第" << n << "项;" << nth << endl;
    cout << endl;
    fibonacci_sequence(n);
    cout << endl;
    long long sum = fibonacci_sum(n);
    cout << "斐波那契数列前" << n << "项和:" << sum << endl;
    system("pause");
    return 0;
}