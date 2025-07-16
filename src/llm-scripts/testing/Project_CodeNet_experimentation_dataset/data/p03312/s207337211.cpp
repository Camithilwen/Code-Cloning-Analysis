#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define Rep(i,n) for(int i = 1; i <= n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main(){
    int n;
    cin >> n;
    V<int> a(n);
    rep(i,n) cin >> a[i];
    V<ll> sums(n+1);
    sums[1] = a[0];
    for(int i = 2; i <= n; i++) {
        sums[i] = a[i-1] + sums[i-1];
    }
    ll ans = infll;
    for(int i = 2; i <= n-2; i++) {

        auto func = [&](int L, int R) {
            int l = L; int r = R;
            while(abs(r-l) > 1) {
                int mid = (r+l)/2;
                ll p = sums[mid]-sums[L];
                ll q = sums[R]-sums[mid];
                if(p < q) l = mid;
                else r = mid;
            }
            Pl res;
            if(abs((sums[l]-sums[L])-(sums[R]-sums[l])) > abs((sums[r]-sums[L])-(sums[R]-sums[r])))
                res = make_pair(sums[r]-sums[L], sums[R]-sums[r]);
            else
                res = make_pair(sums[l]-sums[L], sums[R]-sums[l]);
            return res;
        };

        Pl a = func(0,i);
        Pl b = func(i,n);
        ll tmp = max({a.fi, a.se, b.fi, b.se}) - min({a.fi, a.se, b.fi, b.se});
        chmin(ans, tmp);
    }
    cout << ans << endl;
}