#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e3+10;
const LL MOD=1e9+7;
int n,m,px[N*N],py[N*N];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		int x; scanf("%d",&x);
		if (px[x]) { puts("0"); return 0; }
		px[x]=1;
	}
	for (int j=1;j<=m;j++) {
		int y; scanf("%d",&y);
		if (py[y]) { puts("0"); return 0; }
		py[y]=1;
	}
	
	LL ans=1,usedN=0,usedM=0;
	for (LL i=n*m;i;i--) {
		if (px[i] && py[i]) { usedN++; usedM++; continue; }
		if (px[i]) { usedN++; ans=(ans*usedM)%MOD; }
		if (py[i]) { usedM++; ans=(ans*usedN)%MOD; }
		if (!px[i] && !py[i]) ans=(ans*(usedN*usedM-(n*m-i)))%MOD;
	}
	cout<<ans;
	return 0;
}