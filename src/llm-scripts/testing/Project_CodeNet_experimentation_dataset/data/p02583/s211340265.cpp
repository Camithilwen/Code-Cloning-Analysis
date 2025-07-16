#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define sz(x) int(x.size())
#define bitsz(x) int(__builtin_popcount(x))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb(x) push_back(x)
#define INF 1e9
#define LINF 1e18
#define mod 1000000007
template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
const int di[4] = {1,0,-1,0};
const int dj[4] = {0,1,0,-1};


int main() {
    int n; cin >> n;
    vector<ll> l(n);
    rep(i,n) cin >> l[i];
    int ans = 0;
    rep(i,n) {
        for (int j=i+1; j<n; j++) {
            for (int k=j+1; k<n; k++) {
                if (l[i]==l[j] || l[j]==l[k] || l[k]==l[i]) continue;
                if (l[i]+l[j]>l[k] && l[j]+l[k]>l[i] && l[k]+l[i]>l[j]) ans++;
            }
        }
    }
    cout << ans << endl;
}