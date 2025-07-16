#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5+5, MOD = 998244353;
int n, m, k, p[N];

int mul(int x, int y) {
    ll tmp = 1LL * x * y;
    return tmp % MOD;
}
int add(int x, int y) {
    ll tmp = 1LL*x + 1LL*y;
    return tmp % MOD;
}
int pow(int x, int e) {
    int res = 1;
    for(; e; e>>=1) {
        if(e&1) res = mul(res, x);
        x = mul(x, x);
    }
    return res;
}
int inv(int x) {
    return pow(x, MOD-2);
}
int C(int x, int y) {
    int det = mul(p[x], p[y-x]);
    return mul(p[y], inv(det));
} 
void preprocess() {
    p[0] = 1;
    for(int i=1; i<N; i++)
        p[i] = mul(p[i-1], i);
}
int main() {
    preprocess();
    cin >> n >> m >> k;
    int ans = 0;
    for(int t=n-k; t<=n; t++) {
        int tmp = mul(m, pow(m-1, t-1));
        tmp = mul(tmp, C(n-t, n-1));
        ans = add(ans, tmp);
    }
    cout << ans;
}