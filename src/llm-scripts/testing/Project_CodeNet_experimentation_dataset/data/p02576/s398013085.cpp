#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
#define rep(i, s, e) for (int i = s; i < e; i++)
#define endl '\n'
int main()
{
    int n, x, t;
    cin >> n >> x >> t;
    int ans = (n +x-1)/x * t;
    cout << ans << endl;
}