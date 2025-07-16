#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 1<<17, mlg = 17, mod = 1e9 + 7;
ll n, l, q, x[maxn], go[maxn][mlg];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i];
	cin >> l >> q;
	for(int i = 1, j = 1; i <= n; i++) {
		while(j < n && x[j+1]-x[i] <= l) j++;
		go[i][0] = j;
		//cout << j << " ";
	}
	for(int j = 1; j < mlg; j++)
		for(int i = 1; i <= n; i++)
			go[i][j] = go[go[i][j-1]][j-1];
	int a, b;
	while(q--) {
		cin >> a >> b;
		if(a > b) swap(a, b);
		int ans = (a!=b);
		for(int i = mlg; i--;) if(go[a][i] && go[a][i] < b) {
			//cout << a << " " << i << '\n';
			a = go[a][i], ans += 1<<i;
		}
		cout << ans << '\n';
	}
}
