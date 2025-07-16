///usr/bin/g++ -O2 $0 -o ${0%.cpp} && echo "----------" && ./${0%.cpp}; exit;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii; 
 
const int N = 1005; 
const int mod = 1e9 + 7;
 
#define mul(a, b) ((ll) (a) * (b) % mod)
 
int f[N][N], n, a, b, c, d, fact[N], inv[N][N];
 
inline int Pow(int a, int p) {
    int ret = 1; while(p) {
        if(p & 1) ret = mul(ret, a); 
        a = mul(a, a); 
        p >>= 1;
    } return ret;
}
 
void precalc() {
    fact[0] = 1; 
    for(int i = 1; i < N; ++i) 
        fact[i] = mul(fact[i - 1], i); 
    inv[N - 1][1] = Pow(fact[N - 1], mod - 2); 
    for(int i = N - 2; i >= 0; --i) 
        inv[i][1] = mul(inv[i + 1][1], i + 1); 
    for(int i = 0; i < N; ++i) {
        inv[i][0] = 1; 
        for(int j = 2; j < N; ++j) {
            inv[i][j] = mul(inv[i][j - 1], inv[i][1]); 
        }
    }
}
 
 
int main(int argc, char const *argv[]) {
    precalc();
    scanf("%d %d %d %d %d", &n, &a, &b, &c, &d); 
 
    for(int i = 0; i <= n; ++i) f[0][i] = 1;  
    for(int i = 1; i <= n; ++i) {
        for(int j = a; j <= b; ++j) {
            f[i][j] = f[i][j - 1]; 
            for(int k = c; k <= d && j * k <= i; ++k) {
                f[i][j] += mul(fact[i], mul(f[i-j*k][j-1], mul(inv[i-j*k][1], mul(inv[j][k], inv[k][1])))); 
                if(f[i][j] >= mod) f[i][j] -= mod; 
            } 
        }
    }
    printf("%d\n", f[n][b]);
}