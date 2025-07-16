#include <bits/stdc++.h>
using namespace std;

#define task "test"
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define openfile  if (fopen(task ".inp","r")){freopen(task ".inp","r",stdin);freopen(task ".out","w",stdout);}
#define ll long long
#define pii pair <int, int>
#define pll pair <ll, ll>
#define all(c) c.begin(), c.end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second

const int INF = 1E9;
const int MOD = 1E9 + 7;
const int N = 1000 + 10;

int t = 1;

ll n, a, b, c, d;
ll Fact[N], Inv[N], F[N][N];

ll POW(ll n, ll k)
{
    if (k == 1) return n;
    ll tmp = POW(n, k / 2);
    tmp = tmp * tmp % MOD;

    if (k & 1) return tmp * n % MOD;
    return tmp;
}

void Input()
{
    cin >> n >> a >> b >> c >> d;
}

void Prepare()
{
    Fact[0] = Inv[0] = Fact[1] = Inv[1] = 1;
    for (int i = 2; i <= n; i++) Fact[i] = Fact[i - 1] * (ll) (i) % MOD;
    for (int i = 2; i <= n; i++) Inv[i] = POW(Fact[i], MOD - 2);
}

ll Comb(ll n, ll k)
{
    if (n < k) return 0;
    return Fact[n] * Inv[k] % MOD * Inv[n - k] % MOD;
}

void Solve()
{
    F[a - 1][0] = 1;

    for (int i = a; i <= b; i++)
        for (int j = 0; j <= n; j++) {
            F[i][j] = F[i - 1][j];
            //cout << "Pre : " << F[i][j] <<" - > ";
            for (int k = c; k <= d && i * k <= j; k++) {
                F[i][j] += F[i - 1][j - i * k] * Comb(j, j - i * k) % MOD * Fact[i * k] % MOD * POW(Inv[i], k) % MOD * Inv[k] % MOD;
                F[i][j] %= MOD;
              //  if (i == 1 && j == 3) cout << F[i][j] << " " << k << endl;
            }
          //  cout << i << " " << j << " " << F[i][j] << endl;
        }
    cout << F[b][n];
}

int main()
{
    openfile;
    // cin >> t;
    while (t--) {
        Input();
        Prepare();
        Solve();
    }
}



