#include <bits/stdc++.h>
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int MOD=1e9+7;
int n,x[3], dp[40][1<<16];
void printbin(int n, int b = 31) {
	for(int i=b-1; i>=0; i--) printf("%d", n>>i&1);
}
int Count(int p, int b) {
	if(p==n) return 1;
	int& res=dp[p][b];
	if(res!=-1) return res;
	res=0;
	int i,t=b,c=0,f=0;
	bool chk[11]={0};
	while(t>0) t>>=1,c++;
	for(i=0;i<c;i++) {
		if(i&&(~b>>(i-1)&1)) continue;
		if(~b>>(i+x[0]-1)&1) continue;
		if(~b>>(i+x[0]+x[1]-1)&1) continue;
		t=i+x[0]+x[1]+x[2]-c;
		if(t>=1&&t<=10)
			chk[t]=1;
	}
	t=b;
	for(int i=1;i<=10;i++) {
		if(chk[i]) continue;
		while(c+i>16) {
			while(t>0&&!(t&1))t>>=1,c--;
			t>>=1,c--;
		}
		res=(res+Count(p+1,t|(1<<(c+i-1))))%MOD;
	}
	//printf("dp[%d][%d]:%d\n",p,b,res);
	//printf("dp[%d][",p); printbin(b,16); printf("]:%d\n",res);
	return res;
}
int main() {
	memset(dp,-1,sizeof(dp));
	scanf("%d%d%d%d",&n,x,x+1,x+2);
	int p=1;
	for(int i=1;i<=n;i++) p=10ll*p%MOD;
	printf("%d", (p-Count(0,0)+MOD)%MOD);
	return 0;
}