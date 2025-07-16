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


ll v[55];

int main(){
    int n, k;
    cin >> n >> k;
    rep(i, n) cin >> v[i];

    int m = min(n, k);

    ll ans = 0;

    rep(i, m+1){ // i個取り出す時を考える
        rep(l, i+1){
            vector<ll> tmp;
            rep(j, l) tmp.push_back(v[j]);
            int r = i - l;
            // cout << l << " " << r << endl;
            for(int j = n-1; j >= n - r; j--) tmp.push_back(v[j]);
            // rep(j, tmp.size()) cout << tmp[j] << " ";
            // cout << endl;

            sort(tmp.begin(), tmp.end());

            int res = k - (l+r);
            ll s = 0;
            rep(j, tmp.size()){
                if (tmp[j] < 0 && res > 0){
                    res--;
                }
                else s += tmp[j];
            }
            ans = max(s, ans);
        }
    }

    cout << ans << endl;

    return 0;
}
