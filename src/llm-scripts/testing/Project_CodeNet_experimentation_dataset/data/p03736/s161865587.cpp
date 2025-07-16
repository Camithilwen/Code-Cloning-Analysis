#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const LL inf=0x3f3f3f3f3f3f3f3fll;
const int MX=200005;
int n,m,x,y;LL ad,f[MX],ans;
LL f1[MX],f2[MX];
void add1(int x,LL k){for(;x<=n&&k<f1[x];x+=x&-x)f1[x]=k;}
LL que1(int x){LL k=inf;for(;x;x-=x&-x)k=min(k,f1[x]);return k;}
void add2(int x,LL k){for(;x&&k<f2[x];x-=x&-x)f2[x]=k;}
LL que2(int x){LL k=inf;for(;x<=n;x+=x&-x)k=min(k,f2[x]);return k;}
void wk(){
	y=x,cin>>x;
	LL v=min(que1(x)+x,que2(x)-x)+ad;ad+=abs(x-y);
	if(v-ad<f[y])f[y]=v-ad,add1(y,f[y]-y),add2(y,f[y]+y);
}
int main(){
	int i;
	cin>>n>>m>>x>>y;
	for(i=1;i<=n;i++)f[i]=f1[i]=f2[i]=inf;
	for(f[y]=0,add1(y,-y),add2(y,y);m--;)wk();
	for(ans=inf,i=1;i<=n;i++)ans=min(ans,f[i]);
	cout<<ans+ad<<endl;
	return 0;
}