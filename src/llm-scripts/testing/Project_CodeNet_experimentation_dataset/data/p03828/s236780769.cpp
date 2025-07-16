#include <bits/stdc++.h>
using namespace std;
int p[168], q[168], mod = 1000000007;
int primecheck(int n) {
    int d = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0) d++;
        if (d == 2) break;
    }
    if (d > 1) return 0;
    else return 1;
}
int main() {
    int k = 0, n, l;
    long long f = 1;
    for (int i = 0; i < 168; i++) q[i] = 0;
    for (int i = 2; i <= 997; i++)
    {
        if (primecheck(i) == 1)
        {
            p[k] = i;
            k++;
        }
    }
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        k = 0, l = i;
        while (l != 1)
        {
            if (l % p[k] == 0)
            {
                l /= p[k];
                q[k]++;
            }
            else k++;
        }
    }
    for (int i = 0; i < 168; i++)
    {
        f *= (q[i] + 1);
        f %= mod;
    }
    cout << f;
}