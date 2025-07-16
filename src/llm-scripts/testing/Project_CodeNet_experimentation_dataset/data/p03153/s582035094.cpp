#include<map>
#include<set>
#include<bitset>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<chrono>
#include<stack>
#include<fstream>
#include<list>
#include<math.h>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define SIZE(a) ll(a.size())
#define vll vector<ll> 
#define MEMSET(a, n, m) for(ll i=0;i<=n;i++) a[i] = m
#define BIT(n) (ll(1)<<n)
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end()) 
#define UNIQUE_ARRAY(a,x) unique(a + 1, a + x + 1) - a - 1
#define SORT(a,n) sort(a+1,a+n+1)
#define SORT_O(a,n,order) sort(a+1,a+n+1,order)
#define PER(i,y,x) for(ll i=y;i>=x;i--)
typedef long long ll;
using namespace std;
double const PI = 3.1415926535;

struct edge{	
	ll from;  long long to; long long cost;
	bool operator<(const edge& rhs) const {
		return cost > rhs.cost;
	}
};

ll const MAX_UF = 200005;
ll parent[MAX_UF];
ll rk[MAX_UF];


void init(ll n) {
	for (ll i = 1; i <= n; i++) {
		parent[i] = i;
		rk[i] = 1;
	}
}

ll find(ll x) {
	if (parent[x] == x) {
		return x;
	}
	parent[x] = find(parent[x]);
	return parent[x];
}

bool same(ll x, ll y) {
	return find(x) == find(y);
}

void unite(ll x, ll y) {
	if (!same(x, y)) {
		x = parent[x];
		y = parent[y];
		if (rk[x] < rk[y]) {
			parent[x] = y;
		}
		else {
			parent[y] = x;
			if (rk[x] == rk[y]) {
				rk[x]++;
			}
		}
	}
}


ll const MAX_seg = 800005; //4倍に取っておく
ll segtree[MAX_seg];
ll mintree[MAX_seg];

//演算
ll op(ll x, ll y) {
	return min(x, y);
}
//init valueの変更を忘れない
ll const INIT_VALUE = 1e17;
ll n_ = 1;

void init_seg(ll n) {
	while (n_ <= n) {
		n_ *= 2;
	}
	REP(i, 1, n_ * 2) {
		segtree[i] = INIT_VALUE;
	}
	REP(i, n_ , n_ * 2) {
		mintree[i] = i - n_;
	}
	REP(i, 1, n_ - 1) {
		mintree[i] = mintree[i * 2];
	}
}

//k番目をxでupdate
void update(ll k, ll x) {
	k += n_;
	segtree[k] = x;
	while (k >= 1) {
		k /= 2;
		segtree[k] = op(segtree[k * 2], segtree[k * 2 + 1]);
		if (segtree[k * 2] > segtree[k * 2 + 1]) {
			mintree[k] = mintree[k * 2 + 1];
		}
		else {
			mintree[k] = mintree[k * 2];
		}
	}
}

ll val_o(ll a, ll b, ll k, ll l, ll r,ll& g) {
	if (a <= l && r <= b) {
		g = mintree[k];
		return segtree[k];
	}
	else if (r <= a || b <= l) {
		//ここの値注意
		return INIT_VALUE;
		g = mintree[k];
	}
	else {
		ll g1 = 0; ll g2 = 0;
		ll x1 = val_o(a, b, k * 2, l, (l + r) / 2, g1);
		ll x2 = val_o(a, b, k * 2 + 1, (l + r) / 2, r, g2);
		if (x1 > x2) {
			g = g2;
		}else{
			g = g1;
		}
		return op(x1, x2);
	}

}

//[a,b)のvalueを求める
ll val(ll a, ll b, ll& g) {
	return val_o(a, b, 1, 0, n_, g);
}

ll const MAX = 2e5;
ll n, d;
ll a[MAX];
ll ord[MAX];

bool orders(ll x, ll y) {
	return a[x] < a[y];
}

ll bignumber = 5e16;

priority_queue<edge> pq;

void makegraph(ll type) {
	init_seg(n);
	REP(i, 1, n) {
		ll cur = ord[i];
		if (i > 1) {
			ll min_i = 0;
			ll min_a;
			if (type == 1) {
				min_a = val(cur + 1, n + 1, min_i);
			}
			else {
				min_a = val(1, cur, min_i);
			}
		//	cout << type << " " << cur << " " << min_a << endl;
			if (min_a <= bignumber) {
				ll c;
				if (type == 1) {
					c = min_a - d * cur + a[cur];
				}
				else {
					c = min_a + d * cur + a[cur];
				}
				pq.push({ min_i,cur,c });
			}
		}
		ll t = a[cur] + type * cur * d;
		update(cur, t);
	//	cout << "?" << cur << " " << t << endl;
	}
}

int main() {
	cin >> n >> d;
	REP(i, 1, n) {
		cin >> a[i];
	}
	REP(i, 1, n) {
		ord[i] = i;
	}
	SORT_O(ord, n, orders);
	makegraph(1);
	makegraph(-1);
	ll ans = 0;
	init(n);
	while (!pq.empty()) {
		edge cur = pq.top();
		pq.pop();
		//cout << "!" << cur.cost << endl;
		if (!same(cur.from, cur.to)) {
			ans += cur.cost;
			unite(cur.from, cur.to);
		}
	}
	cout << ans << endl;
}
