#include <bits/stdc++.h>
#include <atcoder/all>

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

using namespace std;
using namespace atcoder;

using ll = long long;
using P = pair<int,int>;
constexpr int INF = 1001001001;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main() {
    int n, q;
    cin >> n >> q;
    fenwick_tree<ll> fw(n);
    rep (i, n) {
        int a;
        cin >> a;
        fw.add(i, a);
    }
    rep (i, q) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 0) fw.add(a, b);
        else cout << fw.sum(a, b) << endl;
    }
    
    return 0;
}
