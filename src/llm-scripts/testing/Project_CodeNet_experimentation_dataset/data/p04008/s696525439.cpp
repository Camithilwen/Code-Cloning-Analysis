#include <bits/stdc++.h>
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define mid ((x + y) / 2)
#define left (ind * 2)
#define right (ind * 2 + 1)
#define mp make_pair
#define timer ((double)clock() / CLOCKS_PER_SEC)
#define endl "\n"
#define spc " "
#define d1(x) cerr<<#x<<":"<<x<<endl
#define d2(x, y) cerr<<#x<<":"<<x<<" "<<#y<<":"<<y<<endl
#define d3(x, y, z) cerr<<#x<<":"<<x<<" "<<#y<<":"<<y<<" "<<#z<<":"<<z<<endl
#define fast_io() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<double, double> dd;

const int N = (int)(1e6 + 5);
const int LOG = (int)(20);

int n, nx[N], ans, k, f, nd[N], fl, one;
vector<int> v[N];

int dfs(int x) {
	int re = 0;
	for(auto i : v[x]) {
		int val = dfs(i);
		if(val == k)
			ans++;
		else
			re = max(re, val);
	}
	return re + 1;
}

int main() {
	fast_io();
	// freopen("inp.in", "r", stdin);

	cin >> n >> k;
	if(k > n)
		k = n + 10;
	for(int i = 1; i <= n; i++)
		cin >> nx[i];
	if(nx[1] != 1) {
		fl = 1;
		nx[1] = 1;
	}
	for(int i = 1; i <= n; i++)
		if(i != nx[i])
			v[nx[i]].pb(i); 
	for(auto i : v[1]) 
		dfs(i);
	cout << ans + fl;
}