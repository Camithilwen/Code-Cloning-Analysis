#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define abdelrahman010 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n , m , a , b , pref1 , pref2;
int main() {
    abdelrahman010
    cin >> n >> m;
    for(int i = 0;i < n;i++) {
        int x;
        cin >> x;
        if(i)
            a = (a + ((1ll * x * i) % mod - pref1 + mod) % mod) % mod;
        pref1 = (pref1 + x) % mod;
    }
    int ans = 0;
    for(int i = 0;i < m;i++) {
        int x;
        cin >> x;
        b = ((1ll * x * i) % mod - pref2 + mod) % mod;
        ans = (ans + (1ll * a * b) % mod) % mod;
        pref2 = (pref2 + x) % mod;
    }
    cout << ans;
    return 0;
}