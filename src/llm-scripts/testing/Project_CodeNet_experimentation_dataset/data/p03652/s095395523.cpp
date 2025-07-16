#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

ll a[310][310];
bool ok[310];
ll ans = LINF;

int main(){
    int n, m;
    cin >> n >> m;
    rep(i, n) rep(j, m) cin >> a[i][j], a[i][j]--;

    rep(i, 310) ok[i] = 1;

    rep(i, m){
        int selected[310] = {};
        rep(j, n){
            rep(k, m){
                if (ok[a[j][k]]) {
                    selected[a[j][k]]++;
                    break;
                }
            }
        }
        ll mx = 0, idx = -1;
        rep(j, m){
            if(selected[j] == 0) continue;
            if(selected[j] > mx){
                mx = selected[j];
                idx = j;
            }
        }
        ans = min(ans, mx);
        ok[idx] = 0;
    }

    cout << ans << endl;

    return 0;
}
