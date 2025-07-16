#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

vector<int> v[505];

int main(){
    int n, m, Q;
    cin >> n >> m >> Q;
    rep(i, m) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        v[l].push_back(r);
    }
    rep(i, n) {
        sort(whole(v[i]));
    }
    rep(qi, Q) {
        int p, q;
        cin >> p >> q;
        p--; q--;
        int ans = 0;
        for (int i=p; i<=q; i++) {
            auto it = upper_bound(whole(v[i]), q);
            ans += (it-v[i].begin());
        }
        cout << ans << endl;
    }
    
    
    return 0;
}
