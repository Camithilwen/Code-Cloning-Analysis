#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define N 1100005
using namespace std;

typedef long long ll;

ll n, ans, kac, a[N], pre[N], dp[N], fen[N], of[N];
vector < int > g[N];

ll fe(ll a, ll us){
	if(us <= 1)
		return (us)?a:1ll;
	ll t = fe(a, us/2);
	return (us&1)?(t*t%mod)*a%mod : t*t%mod;
}

void up(int x, int y){
	for(; x < N; x += x&-x)
		fen[x] += y;
}

int qu(int x){
	int ans = 0;
	for(; x > 0; x -= x&-x)
		ans += fen[x];
	return ans;
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	scanf("%lld",&n);
	for(int i = 1; i <= n; i++){
		scanf("%lld",a + i);
		pre[i] = pre[i - 1]^a[i];
		g[pre[i]].pb(i);
		if(!pre[i])
			up(i, 1);
	}
	if(pre[n] != 0){
		ll sif = 1;
		ll bir = 0;
		for(int i = 1; i <= n; i++){
			if(pre[i] == pre[n])
				bir = (bir + sif)%mod;
			else if(pre[i] == 0)
				sif = (sif + bir)%mod;
		}
		printf("%lld\n", sif);
		return 0;
	}
	kac = (int)g[pre[n]].size();
	ans = (ans + fe(2, kac - 1))%mod;

	// cout << ans << endl;

	for(int i = 1; i < N; i++){
		if(g[i].empty())
			continue;
		int u = (int)g[i].size(), ek = 1;
		of[0] = dp[0] = 1;
		// cout << i << " " << u << endl << " -> " << g[i][0] << " ";
		for(int j = 1; j < u; j++){
			int ara = qu(g[i][j]) - qu(g[i][j - 1]);
			dp[j] = (dp[j - 1] - 1 + of[j - 1]*ara%mod + 1)%mod;
			of[j] = (of[j - 1] + dp[j])%mod;
			// cout << "(" << ara << ") " << g[i][j] << " - " << dp[j] << " ";
		}
		ans = (ans + of[u - 1])%mod;
		// cout << " = " << of[u - 1] << endl;
	}

	printf("%lld\n", ans);
	return 0;
}