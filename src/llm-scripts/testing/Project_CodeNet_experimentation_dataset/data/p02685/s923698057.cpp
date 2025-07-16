#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define pb push_back
#define endl '\n'
#define snd second
#define fst first
#define fastio cin.tie(NULL),cout.sync_with_stdio(true)

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector <int> vi;
typedef pair <int, int> ii;

const ll mod = 998244353;
//const ll mod = 1e9 + 7;
const ll INF = (1LL<<50);
const double EPSILON = 0.001;
const int N = 200005;
ll mul(ll a, ll b){
	return a*b%mod;
}
ll add(ll a, ll b){
	a += b;
	if(a >= mod)
		a-=mod;
	return a;
}
ll expo(ll a, ll b){
	ll r = 1;
	for(;b; b >>= 1, a = mul(a,a))
		if(b&1)
			r = mul(r, a);
	return r;
}
ll fact[N], ifact[N];
void init(){
	fact[0] = 1;
	for(ll i = 1; i < N; i++)
		fact[i] = mul(i, fact[i-1]);
	ifact[N-1] = expo(fact[N-1], mod-2);
	for(ll i = N-2; i >= 0; i--)
		ifact[i] = mul(ifact[i+1], i+1);
}
ll ncr(ll n, ll r){
	if(n < r)return 0;
	return mul(fact[n], mul(ifact[r], ifact[n-r]));
}
/*
	from n total blocks, (n-1) is the total of adj pairs.
	assuming we want to make only k pairs to have the same color
	doesn't matter how those pairs are distributed , the ways to
	color them always follow that formula : C(n-1,k) * m * 1^(k) * (m-1)^(n-1-k)
	so the final answer is:
			i:(0,k) Σ C(n-1,i) * m * 1^i * (m-1) ^(n-1-i)
*/
int main(){
	fastio;
	init();
	int n,m,k,ans = 0;
	cin >> n >> m >> k;
	for(int i = 0; i <= k; i++)
		ans = add(ans, mul(ncr(n-1, i), mul(m, expo(m-1, n-1-i))));
	cout << ans << '\n';
	return 0;
}
