#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int N = 1e6 + 5, mod = 1e9 + 7;
bool A[N], B[N];
int n, m, x;
LL ans = 1, r, c, tc, tr;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(A[x]) {return cout << 0, 0;}
        A[x] = 1;
    }

    for(int i = 0; i < m; i++) {
        cin >> x;
        if(B[x]) {return cout << 0, 0;}
        B[x] = 1;
    }

    for(int i = n * m; i > 0; i--) {
        tc = c, tr = r;
        if(A[i]) {tr = 1, r++;}
        if(B[i]) {tc = 1, c++;}
        if(A[i] || B[i]) {ans *= (tc * tr) % mod;}
        else ans *= (tc * tr - (n * m - i)) % mod;
        ans %= mod;
    }
    cout << ans;
}