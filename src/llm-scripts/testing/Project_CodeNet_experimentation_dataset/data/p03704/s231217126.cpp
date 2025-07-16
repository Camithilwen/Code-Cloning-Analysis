#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#define ll long long
using namespace std;

int d,dep,m;
ll ans;
int c[20],c0[20];
ll f[20],a[20];

void dfs(int k,ll w,ll s){
	if (k==m){
		ans+=1ll*(w==d)*s;
		return;
	}
	if (abs(w-1ll*d)>a[k]*20) return;
	int i,cnt;
	for (i=0;i<20;i++){
		if (!k) cnt=c0[i];
		else cnt=c[i];
		if (!a[k]) cnt=i<10;
		if (!cnt) continue;
		dfs(k+1,w+a[k]*1ll*(i-10),s*1ll*cnt);
	}
}

void solve(int n){
	m=0;
	int i;
	for (i=0;i<n;i++){
		if (i>n-i-1) break;
		a[m++]=f[n-i-1]-f[i];
	}
	dfs(0,0,1);
}

int main(){
	int i,j;
	f[0]=1; for (i=1;i<=18;i++) f[i]=f[i-1]*10ll;
	for (i=0;i<=9;i++)
		for (j=0;j<=9;j++) c[i-j+10]++;
	for (i=0;i<=9;i++)
		for (j=1;j<=9;j++) c0[i-j+10]++;
	scanf("%d",&d);
	for (dep=1;dep<=19;dep++) solve(dep);
	printf("%lld\n",ans);
	return 0;
}