#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,i,j,cnt,xlh,ans,op,a[302][302],b[302],v[302];
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)v[i]=1;
	ans=n;
	for(i=1;i<=n;i++)
	 for(j=1;j<=m;j++)scanf("%d",&a[i][j]);
	for(cnt=1;cnt<m;cnt++){
		for(i=1;i<=m;i++)b[i]=0;
		for(i=1;i<=n;i++)
		 for(j=1;j<=m;j++)if(v[a[i][j]]){
		 	b[a[i][j]]++;break;
		 }
		xlh=0;
		for(i=1;i<=m;i++){
			if(b[i]>xlh)op=i;
		 xlh=max(xlh,b[i]);
	 }
		ans=min(ans,xlh);
		v[op]=0;
	}
	printf("%d",ans);
}