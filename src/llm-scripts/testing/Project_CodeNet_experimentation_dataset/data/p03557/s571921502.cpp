#include <bits/stdc++.h>
using namespace std;
// define
#define int long long
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
#define ZIP(v) sort(all(v)),UNIQUE(v)
#define ADD(a, b) a = (a + b) % mod
#define SUB(a, b) a = (a+mod-b)%mod
#define MUL(a, b) a = (((a)%mod) * ((b)%mod)) % mod
#define rollcall cout << "I'm Sucu." << endl;
#define repi(i,m,n) for(int i = m;i < n;i++)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define rep(i,n) repi(i,0,n)
#define rrep(i,n) repi(i,1,n+1)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define dmp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define fi first
#define se second
// typedef
typedef complex<double> Point;
typedef pair<int, int> P;
typedef pair<int, P> PP;
typedef pair<P, int> Pi;
typedef vector<int> vi;
typedef deque<int> dq;
const int inf = 1e9+7;
const int INF = 1e18+7;
const int mod = 1e9+7;
// int sum = accumulate(a, a+n, 0LL);
// int mx = max_element(a, a+n);
// int mn = min_element(a, a+n);
// int cnt = count(a, a+n, k);

int N;

signed main()
{
    cin >> N;
    vi A(N), B(N), C(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, N) cin >> C[i];

    sort(all(A));
    sort(all(C));

    int ans = 0;

    rep(i,N)
    {
        auto low = lower_bound(all(A), B[i]);
        int ac = low - A.begin();
        auto high = upper_bound(all(C), B[i]);
        int cc = C.end() - high;
        ans += ac * cc;
    }

    cout << ans << endl;

    return 0;
}