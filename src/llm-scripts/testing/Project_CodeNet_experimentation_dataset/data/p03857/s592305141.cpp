//============================================================================
// Name        : hoba.cpp :)
// Author      : (O_O Diab) (Why_not) (el 3AQ)
// Version     :
// Copyright   : please, Don't touch me :(
// Description : problem (I) in C++
// MAIN IDEA   : max sum of S(X) + S(S(X)) => 100 so brute force
//============================================================================
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define rw freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
#define pb push_back
#define F first
#define S second
#define pf push_front
#define lp(i,a,b) for (int i=a;i<=(int)b;++i)
#define lp2(i,a,b) for (int i=a;i>=b;--i)
#define f(x) return cout<<x<<"\n",0
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(c) c.begin(),c.end()
#define allr(c) c.rbegin(),c.rend()
#define p(x) cout<<#x<<" = { "<<x<<" } \n"
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define EPS 1e-6
// to convert string to number use int a = stoi(string);
// to convert number to string use string s = to_string(int);
#define FAST ios::sync_with_stdio(0),ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define clr(c,x) memset(c,x,sizeof(c));
using namespace __gnu_pbds;
using namespace std;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int dx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
const int N = 2e5 + 5, mod = (int) 1e9 + 7, INF = 0x3f3f3f3f;
vi vv;
vector<vi> v, vec;
set<int> st;
int ans[N] = { }, comp[N] = { };
bool vis[N] = { };
void dfs(int node) {
	vis[node] = true;
	for (auto u : v[node])
		if (!vis[u])
			dfs(u);
	vv.pb(node);
}
int main() {
#ifdef ONLINE_JUDGE
	FAST
#endif
	int n, k, l;
	cin >> n >> k >> l;
	v.resize(n + 1);
	lp(i,1,k)
	{
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	int cnt = 0;
	lp(i,1,n)
	{
		if (vis[i])
			continue;
		vv.clear();
		dfs(i);
		cnt++;
		for (auto u : vv)
			comp[u] = cnt;
	}
	clr(vis, 0);
	v.clear();
	v.resize(n + 1);
	vec.resize(n + 1);
	lp(i,1,l)
	{
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	lp(i,1,n)
	{
		if (vis[i])
			continue;
		vv.clear();
		dfs(i);
		st.clear();
		for (auto u : vv) {
			vec[comp[u]].pb(u);
			st.insert(comp[u]);
		}
		for (auto u : st) {
			for (auto k : vec[u])
				ans[k] = vec[u].size();
			vec[u].clear();
		}
	}
	lp(i,1,n)
		cout << ans[i] << " ";
	return 0;
}