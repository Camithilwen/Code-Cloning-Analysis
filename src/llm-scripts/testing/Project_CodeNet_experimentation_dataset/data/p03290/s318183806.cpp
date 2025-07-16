#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

const ll INF = 1LL<<60;

int main(){
    int d;
    ll g;
    cin >> d >> g;
    VP q(d);
    rep(i,d) cin >> q[i].first >> q[i].second;

    VI p(d);
    rep(i,d) p[i] = i;

    ll ans = INF;
    do{
        VI pp(d);
        rep(i,d) pp[p[i]] = i;

        ll gg = g;
        ll cnt = 0;
        rep(i,d){
            int j = pp[i];
            ll pc = (j + 1) * 100;
            ll num = min((ll)q[j].first, ((gg + (pc-1)) / pc));
            cnt += num;

            gg -= pc * num;
            gg -= q[j].second;

            if (gg <= 0) break;
        }

        ans = min(ans, cnt);

    } while(next_permutation(all(p)));

    cout << ans << endl;
    return 0;
}