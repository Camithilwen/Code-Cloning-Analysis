#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, x;
    cin >> n >> x;
    long long a[n], c = 0;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > x)
        {
            c += a[i] - x;
            a[i] = x;
        }
    }
    for (long long i = 1; i < n; i++)
    {
        if (a[i] + a[i - 1] > x)
        {
            c += a[i] + a[i - 1] - x;
            a[i] = x - a[i - 1];
        }
    }
    cout << c;
}