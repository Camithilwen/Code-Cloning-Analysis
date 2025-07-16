#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using namespace atcoder;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

ll a[500010];
int main(){
    int n, q;
    cin >> n >> q;
    fenwick_tree<ll> fw(n);

    rep(i, n) {
        int a; cin >> a;
        fw.add(i, a);
    }

    rep(i, q){
        int b; cin >> b;
        if (b == 0) {
            int p;
            ll x;
            cin >> p >> x;
            fw.add(p, x);
        }
        else {
            int l, r; cin >> l >> r;
            cout << fw.sum(l, r) << endl;
        }
    }

    return 0;
}
