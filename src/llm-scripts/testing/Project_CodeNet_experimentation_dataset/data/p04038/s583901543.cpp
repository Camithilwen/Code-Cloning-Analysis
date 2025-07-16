#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 2020;
const int Q = N * N;
const int mod = 1e9 + 7;

using namespace std;

int pw(int x, int n)
{
        int res = 1;
        for(; n > 0; n >>= 1){
                if(n & 1){
                        res = 1ll * res * x % mod;
                }
                x = 1ll * x * x % mod;
        }
        return res;
}

int fac[Q], inv[Q];

void make()
{
        fac[0] = 1;
        for(int i = 1; i < Q; i++) fac[i] = fac[i - 1] * 1ll * i % mod;
        inv[Q - 1] = pw(fac[Q - 1], mod - 2);
        for(int i = Q - 2; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
}

int C(int n, int k)
{
        if(k < 0 || k > n) return 0;
        return 1ll * fac[n] * inv[k] % mod * inv[n - k] % mod;
}

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        }
}

int n, k;
int d[N][N];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        make();

        cin >> n >> k;
        if(k == 1){
                cout << 1 << "\n";
                return 0;
        }
        d[0][0] = 1;
        for(int i = 0; i <= n; i++){
                for(int j = i; j <= n; j++){
                        if(i > 0)add(d[i][j], d[i - 1][j]);
                        if(j > 0)add(d[i][j], d[i][j - 1] * 1ll * C(j * (k - 1) + i - 1, k - 2) % mod);
                }
        }
        cout << d[n][n] * 1ll * fac[n] % mod << "\n";
}
