#include<bits/stdc++.h>

using namespace std;
using ll = long long;



int main()
{
    vector<ll> a(300);
    a[0] = 300000;
    a[1] = 200000;
    a[2] = 100000;
    int x, y;
    cin >> x >> y; x--; y--;
    ll ans = a[x] + a[y];
    if(x == y && x == 0)ans += 400000;
    cout << ans << endl;
}