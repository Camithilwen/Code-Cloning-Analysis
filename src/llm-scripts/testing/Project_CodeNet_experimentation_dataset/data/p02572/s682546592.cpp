//product of pairs
#include<bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
int main()
{
    long long int tt;
    tt = 1;
    while (tt--)
    {
        long long int n, i, count = 0;
        cin >> n;
        long long int a[n + 1], p[n + 1];
        for (i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        p[n] = a[n];
        for (i = n - 1; i >= 1; i--)
        {
            p[i] = (p[i + 1] + a[i]) % mod;
        }
        for (i = 1; i <= n - 1; i++)
        {
            count = (count + (a[i] * p[i + 1]) % mod) % mod;
        }
        cout << count << " " << endl;
    }
    return 0;
}