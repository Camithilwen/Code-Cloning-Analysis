#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;

void add(ll& x, ll y) {
    if (x>=mod) x%=mod;
    if (y>=mod) y%=mod;
    x += y;
    if (x>=mod) x%=mod;
}

int n, x;
int a[maxn];
const int N = 1e5;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n>>x;
    for (int i=0; i<n; i++) {
	cin>>a[i];
    }
    sort(a,a+n);
    reverse(a,a+n);
    vector<ll> dp(N+10, 0);
    dp[x] = 1;
    
    for (int i=0; i<n; i++) {
	vector<ll> _dp(N+10);
	for (int x=0; x<=N; x++) {
	    if (dp[x]==0) continue;
	    // use a[i]
	    add(_dp[x%a[i]], dp[x]);
	    // don't use a[i]
	    add(_dp[x], 1ll*(n-i-1)*dp[x]%mod);
	}
	swap(_dp, dp);
    }

    ll res = 0;
    for (int x=0; x<=N; x++) {
	add(res, 1ll*x*dp[x]);
    }
    cout<<res<<endl;    
    
    return 0;
}
