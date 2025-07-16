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

int a[1010], b[1010];
map<int, int> mpa, mpb;

int main(){
    int n, m;
    cin >> n >> m;
    rep(i, n){
        cin >> a[i];
        mpa[a[i]]++;
    }
    rep(i, m){
        cin >> b[i];
        mpb[b[i]]++;
    }
    if (mpa.size() != n || mpb.size() != m || (!mpa[m*n] || !mpb[m*n])) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    ll cnta = 0, cntb = 0;

    for(ll num = n*m; num > 0; num--){
        if (mpa[num] && mpb[num]) {
            cnta++;
            cntb++;
        }
        else if (mpa[num] && !mpb[num]){
            ans *= cntb;
            cnta++;
            ans %= MOD;
        }
        else if (!mpa[num] && mpb[num]){
            ans *= cnta;
            ans %= MOD;
            cntb++;
        }
        else {
            ans *= max(cnta * cntb - (n*m-num), (ll)0);
            ans %= MOD;
        }
    }

    cout << ans << endl;

    return 0;
}