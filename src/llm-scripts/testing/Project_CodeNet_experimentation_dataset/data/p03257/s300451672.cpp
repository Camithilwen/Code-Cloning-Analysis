#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;
ll a[1005][1005];
int n;
int pri[10005],tot;
bool mk[10005];
ll lcm(ll a,ll b) {
	if((!a)||(!b)) return a+b;
	return 1ll*a/__gcd(a,b)*b;
}
int main() {
	scanf("%d",&n);
	if(n==2) {
		printf("4 7\n23 10");
		return 0;
	}
	mk[1] = mk[0] = 1;
	for(int i=2;i<=10000;i++) {
		if(!mk[i]) { pri[++tot]=i; }
		if(tot==1000) break;
		for(int j=1;j<=tot&&1ll*pri[j]*i<=10000;j++) {
			int k = pri[j] * i;
			mk[k] = 1;
			if(i%pri[j]==0) break;
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if((i+j)%2==0) a[i][j] = pri[(i + j) / 2] * pri[n+((i-j)/2+(n+1)/2)];
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if((i+j)%2==1) a[i][j] = lcm( lcm(a[i-1][j],a[i+1][j]),lcm(a[i][j-1],a[i][j+1]) ) + 1;
			printf("%lld ",a[i][j]);
		}
		puts("");
	}
}