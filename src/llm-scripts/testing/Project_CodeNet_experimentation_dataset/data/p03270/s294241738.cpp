#include <bits/stdc++.h>

#define mp make_pair
#define X first
#define Y second
#define FOE(x, a) for(auto x : a)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FOD(i, a, b) for(int i = a; i >= b; i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int N = 2010;
const int MOD = 998244353;

void add(int &x, int y){
    x += y;
    x -= (x >= MOD) * MOD;
}

void sub(int &x, int y){
    x -= y;
    x += (x < 0) * MOD;
}

int n, k, d[2 * N], C[2 * N][2 * N], pow2[N];

int nCk(int n, int k){
    if (n < 0 || n < k || k > n || k < 0)
        return 0;
    return C[n][k];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> k >> n;

    C[0][0] = 1;
    FOR(i, 1, 2 * max(n, k)){
        C[i][0] = 1;
        FOR(j, 1, i){
            add(C[i][j], C[i - 1][j]);
            add(C[i][j], C[i - 1][j - 1]);
        }
    }

    pow2[0] = 1;
    FOR(i, 1, max(n, k))
        pow2[i] = (ll) pow2[i - 1] * 2 % MOD;

    FOR(i, 1, k)
        FOR(j, i + 1, k)
            d[i + j]++;

    FOR(x, 2, 2 * k)
        if (x % 2 == 1){
            int ans = 0;
            FOR(i, 0, d[x])
                add(ans, (ll) pow2[i] * nCk(k - 2 * d[x] + n - 1, n - i) % MOD * nCk(d[x], i) % MOD);
            cout << ans << endl;
        } else {
            int ans = 0;
            FOR(i, 0, d[x]){
                add(ans, (ll) pow2[i] * nCk(k - 2 * d[x] + n - 2, n - i) % MOD * nCk(d[x], i) % MOD);
                add(ans, (ll) pow2[i] * nCk(k - 2 * d[x] + n - 3, n - i - 1) % MOD * nCk(d[x], i) % MOD);
            }
            cout << ans << endl;
        }

    int ans = 0;


    return 0;
}