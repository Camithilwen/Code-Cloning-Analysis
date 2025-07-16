#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
    ll n, a, b, c, d, e;
    cin >> n >> a >> b >> c >> d >> e;

    ld res = n / ld(min({a, b, c, d, e}));

    cout << (ll (ceil(res) + 4)) << "\n"; 

    return 0;
} 
