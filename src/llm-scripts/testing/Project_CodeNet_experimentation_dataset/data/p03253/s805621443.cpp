#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
const int mod=(1e9)+7;
const int M=(1e7)+9;
int n,m,tot,d[maxn],iv[maxn],ivjc[maxn],jc[maxn];
int dp[40][maxn],ans;
vector<int> g[maxn];
struct Haxi {
	int to[maxn],tot,head[M],nxt[maxn],w[maxn];
	void insert(int x,int y) {
		tot++; nxt[tot]=head[x%M];
		head[x%M]=tot; to[tot]=x; w[tot]=y;
	}
	int find(int x) {
		for (int i=head[x%M];i;i=nxt[i])
			if (to[i]==x) return w[i];
		return 0;
	}
} Map;
int C(int x,int y) {
	if (x<y||y<0) return 0;
	return (ll)jc[x]*ivjc[y]%mod*ivjc[x-y]%mod;
}
void update(int &x,int y) {
	x+=y; if (x>=mod) x-=mod;
}
int main() {
	
	read(n); read(m);
	iv[0]=jc[0]=ivjc[0]=iv[1]=jc[1]=ivjc[1]=1;
	for (int i=2;i<maxn;i++) {
		jc[i]=(ll)jc[i-1]*i%mod;
		iv[i]=(ll)(mod-mod/i)*iv[mod%i]%mod;
		ivjc[i]=(ll)ivjc[i-1]*iv[i]%mod;
	}
	for (int i=1;(ll)i*i<=m;i++)
		if (m%i==0) {
			d[++tot]=i;
			if (m/i!=i) d[++tot]=m/i;
		}
	sort(d+1,d+tot+1);
	int x;
	for (int i=1;i<=tot;i++) {
		Map.insert(d[i],i);
		x=d[i];
		for (int j=1;(ll)j*j<=d[i];j++)
			if (x%j==0) {
				g[Map.find(j)].push_back(i);
				if (x/j!=j) g[Map.find(x/j)].push_back(i);
			}
	}
	int mx=min(n,35);
	dp[0][1]=1;
	for (int i=0;i<mx;i++)
	for (int j=1;j<=tot;j++) if (dp[i][j]) {
		for (int k=0;k<g[j].size();k++) if (g[j][k]!=j) {
			update(dp[i+1][g[j][k]],dp[i][j]);
		}
	}
	for (int i=0;i<=mx;i++) {
		update(ans,(ll)dp[i][tot]*C(n,i)%mod);
	}
	printf("%d\n",ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/