#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> eg;
typedef vector<eg> el;
typedef vector<ii> vii;
typedef vector<vii> al;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
vvi g;
int cs[512][512][4];
const int MN = 17;
const int SH = 8;
int am[MN][MN];
int n;
const int MSK = 1<<15;
const int HL = (1<<SH)-1;
void pre() {
	memset(cs,0,sizeof(cs));
	for(int fm=0;fm<=HL;fm++) {
		for(int sm=0;sm<=HL;sm++) {
			for(int id=0;id<4;id++) {
				ll a = fm,b = sm;
				if(id&2) {
					a <<= SH;
				}
				if(id&1) {
					b <<= SH;
				}
				for(int i=0;i<n;i++) {
					if(!((1<<i)&a)) continue;
					for(int j=0;j<n;j++) {
						if(!((1<<j)&b)) continue;
						cs[fm][sm][id] += am[i][j];
					}
				}
			}
		}
	}
}
ll calc(int a, int b) {
	ll res = 0;
	for(int i=0;i<4;i++) {
		int fm=a,sm = b;
		if(i&2) {
			fm >>= SH;
		} else {fm &= HL;}
		if(i&1) {
			sm >>= SH;
		} else {sm &= HL;}
		res += cs[fm][sm][i];
	}
	return res;
}
ll dp[1<<MN][MN];
int main() {
	int m;
	scanf("%d %d",&n,&m);
	memset(am,0,sizeof(am));
	for(int i=0;i<1<<MN;i++) {
		for(int j=0;j<MN;j++) {
			dp[i][j] = 1e12;
		}
	}
	g.assign(n,vi());
	for(int i=0;i<m;i++) {
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		a--;b--;
		am[a][b] = am[b][a] = c;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	pre();
	dp[1][0] = 0;
	for(int i=0;i<(1<<n);i++) {
		for(int j=0;j<n;j++) {
			for(int k=0;k<g[j].size();k++) {
				int u = g[j][k];
				dp[i|(1<<u)][u] = min(dp[i|(1<<u)][u],dp[i][j]+calc(i&(~(1<<j)),1<<u));
			}
			int mm = 1<<n;
			int msk = ((1<<n)-1)&(~i);
			while(1) {
				mm--;
				mm &= msk;
				if(mm <= 0) break;
				dp[mm|i][j] = min(dp[mm|i][j],dp[i][j]+calc(i&(~(1<<j)),mm));
			}
		}
	}
	printf("%lld\n",dp[(1<<n)-1][n-1]);
}