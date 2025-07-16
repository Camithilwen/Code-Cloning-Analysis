#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1.);
int x[233],y[233],n,sz;
double ans,st[666];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
		scanf("%d%d",x+i,y+i);
	for(int i=1;i<=n;i++){
		sz=0;
		for(int j=1;j<=n;j++)
			if(i^j)
				st[++sz]=atan2(x[j]-x[i],y[j]-y[i]);
		sort(st+1,st+sz+1);
		st[0]=st[sz]-2.*pi;
		ans=0;
		for(int j=1;j<=n;j++)
			ans=max(ans,st[j]-st[j-1]-pi);
		printf("%.8f\n",ans/2./pi);
	}
}
