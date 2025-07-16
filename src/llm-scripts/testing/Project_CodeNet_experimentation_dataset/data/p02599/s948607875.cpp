#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define rep(i, a, n) for (int i=(a); i<(n); i++)
#define per(i, a, n) for (int i=(a); i>(n); i--)
typedef long long ll;
const int maxn = 5e5+5;
const int mod = 1e9+7;
using namespace std;

int block, curl, curr, res;
struct qry {
	int id, l, r;
} q[maxn];
int ans[maxn], a[maxn], mp[maxn];

void add(int pos) {
	if (mp[a[pos]]==0) {
		res++;
		mp[a[pos]]=1;
	} else {
		mp[a[pos]]++;
	}
}

void del(int pos) {
	if (mp[a[pos]]-1==0) {
		mp[a[pos]]=0;
		res--;
	} else {
		mp[a[pos]]--;
	}
}

void solve() {
	ll n,m; cin >> n >> m;
	block = sqrt(n);
	rep(i,1,n+1) cin >> a[i];
	rep(i,1,m+1) cin >> q[i].l >> q[i].r, q[i].id=i;
	sort(q+1, q+m+1, [](qry x, qry y) {
		if (x.l/block == y.l/block)
			return x.r < y.r;
		return x.l/block < y.l/block;
	});
	curl = curr = res = 0;
	for (int i=1; i<=m; i++) {
		while(curr > q[i].r)
			del(curr--);
		while(curr < q[i].r)
			add(++curr);
		while(curl > q[i].l)
			add(--curl);
		while(curl < q[i].l)
			del(curl++);
		ans[q[i].id]=res;
	}
	for(int i=1; i<=m; i++) 
		cout << ans[i] << '\n';
}

int main(int argc, char * argv[]) 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef DEBUG
	freopen("C:/Users/Fish_Brother/Desktop/in", "r", stdin);
	//freopen("C:/Users/Fish_Brother/Desktop/out", "w", stdout);
#endif

	//int t; cin >> t; while(t--)
	solve();

    return 0;
}