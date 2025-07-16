#include <bits/stdc++.h>
using namespace std;
// Macros for easier access
#define ll long long
#define endl '\n'
#define F first
#define S second
#define umap unordered_map
#define uset unordered_set
#define test ll cases; cin>>cases; for(ll testCase = 1; testCase <= cases; testCase++)   //test cases
#define fill(name, val) memset(name, val, sizeof(name));
#define mop(a, op, b)    (a%mod op b%mod)%mod
#define error(x) fixed<<setprecision(x) //cout<<error(5)<<someDouble    -> example - 3.14159
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define get(a, n)    for(ll it = 0; it < n; it++)    cin>>a[it];
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug(x) cerr << #x << " : " << (x) << endl
// Constants
#define MX 100001
#define mod 1000000007LL
#define inf 1000000000000000000LL
void init(){
	boost;
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

/*	Author: 🆉🅴🅽🅾🅻🆄🆂	*/

string k;
ll dp[10001][2][101], d;
ll count(ll i, bool tight, ll sum){
	if(i == k.size())	return (sum == 0);
	if(dp[i][tight][sum] != -1)	return dp[i][tight][sum];
	ll ans = 0, high = tight ? k[i]-'0' : 9;
	for(ll j = 0; j <= high; j++)
		ans = mop(ans, +, count(i+1, tight & (j == high), (sum+j)%d));
	return dp[i][tight][sum] = ans;
}
int main(){
	init();	fill(dp, -1);
	cin>>k>>d;
	cout<<(count(0, 1, 0) + mod - 1) % mod;
}
