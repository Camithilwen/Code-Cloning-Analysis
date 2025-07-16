#include<iostream>
using namespace std;

int main(){
while(1){
	int INF=100000100;
	int n,k,ans[105][105],t,a,b,c;
	scanf("%d%d",&n,&k);
	if(n==0&&k==0)break;
	for(int i=1;i<=n+2;i++){
		for(int j=1;j<=n+2;j++){
			ans[i][j]=INF;
			if(i==j)ans[i][j]=0;
		}
	}
	for(int i=0;i<k;i++){
		scanf("%d",&t);
		if(t==0){
			scanf("%d%d",&a,&b);
			if(ans[a][b]==INF)printf("%d\n",-1);
			else printf("%d\n",ans[a][b]);
		}
		if(t==1){
			scanf("%d%d%d",&a,&b,&c);
			if(ans[a][b]>c){
				ans[a][b]=c;
				ans[b][a]=c;
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(ans[i][j]>ans[i][a]+ans[a][b]+ans[b][j])ans[i][j]=ans[i][a]+ans[a][b]+ans[b][j];
						if(ans[i][j]>ans[i][b]+ans[b][a]+ans[a][j])ans[i][j]=ans[i][b]+ans[b][a]+ans[a][j];
					}
				}
			}
		}
	}
}
}