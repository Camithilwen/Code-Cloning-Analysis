#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#define DEBUG true
#ifdef ONLINE_JUDGE
#undef DEBUG
#define DEBUG false
#endif 

using namespace std;

#define TRACE(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << endl;}

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << "[" << *it << " = " << a << "]";
	err(++it, args...);
}

#define MAXN ((ll)2e5+5)
#define MOD ((ll)998244353)
#define INF ((ll)1e9 + 9)
#define ll long long
#define _ << " " <<
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define LOG(x) if(DEBUG) cerr << x << endl;
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl "\n"
#define pii pair<int,int>
#define mid ((l+r)/2)

ll n, m, k;
ll A = 0;
ll ans;

void mulself(ll& a, ll b)
{
	a *= b;
	a %= MOD;
}

ll fast(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1LL)
		{
			res*=a;
			res%=MOD;
		}
		b>>=1LL;
		a*=a;
		a%=MOD;
	}
	return res;
}

ll inv(ll x)
{
	return fast(x, MOD-2);
}

ll C(ll a, ll b)
{
	ll ret = 1;
	for (int i = 0; i < b; ++i)
 		mulself(ret, a-i);

 	for (int i = 2; i <= b; ++i)
 		mulself(ret, inv(i));

 	return ret;
}


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;

	A = m * fast(m-1, n-k-1);
	A %= MOD;

	mulself(A, C(n-1, k));

	ans = (ans + A) % MOD;

	ll B = A;

	for (int i = k-1; i >= 0; --i)
	{
		mulself(B, m-1);
		mulself(B, i+1);
		mulself(B, inv(n-(i+1)));

		ans = (ans + B) % MOD;
	}

	cout << ans << endl;
}

/* stuff you should look for
	* ll overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/