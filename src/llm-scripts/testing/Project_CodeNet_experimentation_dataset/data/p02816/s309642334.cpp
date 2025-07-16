#include<bits/stdc++.h>
using namespace std;
int n,a[200100],b[200100],cnt[200100],res[200100],f[400100],g[200100],nxt[200100];
void kmp(){
	for(int i=2,j=0;i<=n;i++){
		while(j&&g[j+1]!=g[i])j=nxt[j];
		if(g[j+1]==g[i])j++;
		nxt[i]=j;
	}
	for(int i=1,j=0;i<2*n;i++){
		while(j&&g[j+1]!=f[i])j=nxt[j];
		if(g[j+1]==f[i])j++;
		if(j==n)cnt[i-n+1]++,j=nxt[j];
	}
}
bool ok[200100];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),res[i]=0;
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=0;i<30;i++){
		for(int j=1;j<=n;j++)f[j]=f[j+n]=(a[j]&(1<<i))>0,g[j]=(b[j]&(1<<i))>0,cnt[j]=ok[j]=0;
		kmp();
//		for(int j=1;j<=2*n;j++)printf("%d",f[j]);puts("");
//		for(int j=1;j<=n;j++)printf("%d",g[j]);puts("");
//		printf("%d1:",i);for(int j=1;j<=n;j++)printf("%d ",cnt[j]);puts("");
		for(int j=1;j<=n;j++){
			g[j]^=1;
			if(res[j]!=-1&&cnt[j])ok[j]=true;
			cnt[j]=0;
		}
		kmp();
//		printf("%d2:",i);for(int j=1;j<=n;j++)printf("%d ",cnt[j]);puts("");
		for(int j=1;j<=n;j++)if(res[j]!=-1&&cnt[j])res[j]|=(1<<i),ok[j]=true;
		for(int j=1;j<=n;j++)if(!ok[j])res[j]=-1;
	}
	for(int i=1;i<=n;i++)if(res[i]!=-1)printf("%d %d\n",i-1,res[i]);
	return 0;
}