#include<bits/stdc++.h>
const int N=1005,mo=1e9+7;
int n,m,a[N],b[N],i,j,k,ans=1,p,q;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",a+i);std::sort(a+1,a+n+1);
	for(i=1;i<n;++i)if(a[i]==a[i+1])return puts("0"),0;
	for(i=1;i<=m;++i)scanf("%d",b+i);std::sort(b+1,b+m+1);
	for(i=1;i<m;++i)if(b[i]==b[i+1])return puts("0"),0;
	for(i=n+1,j=m+1,k=n*m;k;--k){
		for(;a[i-1]>=k;--i);for(;b[j-1]>=k;--j);
		if(a[i]==k && b[j]==k)continue;
		if(a[i]==k)ans=1ll*ans*(m-j+1)%mo;else if(b[j]==k)ans=1ll*ans*(n-i+1)%mo;
			else p=n*m-k+1,q=(n-i+1)*(m-j+1),ans=p<=q?1ll*ans*(q-p+1)%mo:0;
	}
	printf("%d\n",ans);
	return 0;
}