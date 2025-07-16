#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rrep(i, n) for (ll i = n - 1; i >= 0; i--)
#define Rep(i, r, n) for (ll i = r; i < n; i++)
#define RRep(i, r, n) for (ll i = n - 1; i <= r; i--)
#define debug(x) cout << #x << ' ' << '=' << ' ' << (x) << endl;
#define fs first
#define sc second
#define int long long
#define pb push_back
const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};
const int MOD = (1000000007);
//const int MOD = (998244353);
//const int INF = (1 << 30)-1;
const int INF = (1LL << 60)-1;
const double EPS = (1 >> 30);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}

using Graph = vector<vector<pair<int, int>>>;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    //---------------------------------------------
    
    int n,k;
    cin>>n>>k;
    cout<<n-k+1<<endl;
    
}