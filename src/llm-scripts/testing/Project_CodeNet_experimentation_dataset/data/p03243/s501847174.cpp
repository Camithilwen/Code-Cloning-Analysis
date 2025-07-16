#include<iostream>
using namespace std;
int main ()
{
    int n, a, p, k;
    cin >> n;
    a = n / 100;
    k = a * 100 + a * 10 + a;
    p = (a + 1) * 100 + (a + 1) * 10 + a + 1;
    if(n <= k)
        cout << k;
    else
        cout << p;
    return 0;
}