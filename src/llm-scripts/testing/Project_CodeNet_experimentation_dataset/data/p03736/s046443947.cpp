#include <bits/stdc++.h>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define S second
#define F first
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+10;
/*
dp[i][j] = dp[i-1][j] + |x[i]-x[i-1]|
dp[i][x[i-1]] = min(dp[i][x[i-1]], min(dp[i-1][k] + |k-x[i]|, k=1~n))

owo = dp[i-1][k] + |k-x[i]|, k=1~n
k=1~x[i]: owo = dp[i-1][k] + x[i] - k;
k=x[i]~n: owo = dp[i-1][k] + k - x[i];

sta[j], dp[i][j]-j
stb[j], dp[i][j]+j

dp[b]=0
*/
int n, q, x[N], b;
struct ST
{
	int st[N<<2], lz[N<<2]; //lz: not cover to subnodes, st: merge subnode + lazy
	inline void init()
	{
		memset(st,0x3f,sizeof(st));
	}
	inline void setto (int u, int l, int r, int p, int v)
	{
		if (r<p || p<l) return;
		else if (l==p && p==r) st[u]=v;
		else
		{
			int m = (l+r)/2;
			setto(u<<1,l,m,p,v-lz[u]);
			setto(u<<1|1,m+1,r,p,v-lz[u]);
			st[u] = min(st[u<<1], st[u<<1|1])+lz[u];
		}
	}
	inline void add (int u, int l, int r, int ql, int qr, int v)
	{
		if (r<ql || qr<l) return;
		else if (ql<=l && r<=qr) st[u]+=v,lz[u]+=v;
		else
		{
			int m = (l+r)/2;
			add(u<<1,l,m,ql,qr,v);
			add(u<<1|1,m+1,r,ql,qr,v);
			st[u] = min(st[u<<1], st[u<<1|1])+lz[u];
		}
	}
	inline int query (int u, int l, int r, int ql, int qr)
	{
		if (r<ql || qr<l) return 1e18;
		else if (ql<=l && r<=qr) return st[u];
		else
		{
			int m = (l+r)/2;
			return min(query(u<<1,l,m,ql,qr), query(u<<1|1,m+1,r,ql,qr)) + lz[u];
		}
	}
} sta, stb;

void test ()
{
	int n, t, l, r, a;
	cin >> n;
	while (cin >> t >> l >> r)
	{
		if (t==0) sta.setto(1,1,n,l,r);
		if (t==1) cin >> a, sta.add(1,1,n,l,r,a);
		if (t==2) cout << sta.query(1,1,n,l,r) << '\n';
	}
}
void print ()
{
	int dp, dp_min_i, dp_add_i;
	rep(i,1,n)
	{
		dp = sta.query(1,1,n,i,i)+i;
		dp_min_i = sta.query(1,1,n,i,i);
		dp_add_i = stb.query(1,1,n,i,i);
		de(i), de(dp), de(dp_min_i), de(dp_add_i), dd;
	}
	dd
}

signed main()
{
	XinAi
	cin >> n >> q >> x[0] >> b;
	rep(i,1,q) cin >> x[i];
	sta.init(), stb.init();
	sta.setto(1,1,n,b,-b), stb.setto(1,1,n,b,b);
	
	//print();
	
	rep(i,1,q)
	{
		int owo = min(sta.query(1,1,n,1,x[i])+x[i], stb.query(1,1,n,x[i],n)-x[i]);
		sta.add(1,1,n,1,n,abs(x[i]-x[i-1]));
		stb.add(1,1,n,1,n,abs(x[i]-x[i-1]));
		int qwq = sta.query(1,1,n,x[i-1],x[i-1])+x[i-1];
		if (owo < qwq)
		{
			sta.setto(1,1,n,x[i-1],owo-x[i-1]);
			stb.setto(1,1,n,x[i-1],owo+x[i-1]);	
		}
		//de(i), de(owo), de(qwq), de(owo-x[i-1]), de(owo+x[i-1]), dd print();
	}
	int res=9e18;
	rep(i,1,n) res = min(res, sta.query(1,1,n,i,i)+i);
	cout << res << '\n';
}