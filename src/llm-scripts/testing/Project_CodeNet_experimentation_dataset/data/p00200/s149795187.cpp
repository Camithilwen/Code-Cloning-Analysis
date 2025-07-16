#include <stdio.h>
#define INF 10000000

int main(void){
	int n,m;
	
	while(scanf("%d %d",&m,&n),n,m){
		int i,j;
		int a,b,cost,time,c;
		int DPc[256][256];
		int DPt[256][256];
		int k,ans[256];
		
		for(i=0;i<256;i++){
			for(j=0;j<256;j++){
				if(i==j){
					DPc[i][j]=0;
					DPt[i][j]=0;
				}
				else{
					DPc[i][j]=INF;
					DPt[i][j]=INF;
				}
			}
		}
		
		for(i=0;i<m;i++){
			scanf("%d %d %d %d", &a, &b, &cost, &time);
			DPc[a][b]=cost;
			DPc[b][a]=cost;
			DPt[a][b]=time;
			DPt[b][a]=time;
		}
		
		for(k=0;k<=n;k++){
			for(i=0;i<=n;i++){
				for(j=0;j<=n;j++){
					if(DPt[i][k]+DPt[k][j]<DPt[i][j]){
						DPt[i][j]=DPt[i][k]+DPt[k][j];
					}
					if(DPc[i][k]+DPc[k][j]<DPc[i][j]){
						DPc[i][j]=DPc[i][k]+DPc[k][j];
					}
				}
			}
		}
		
		scanf("%d", &m);
		for(i=0;i<m;i++){
			scanf("%d %d %d", &a, &b, &c);
			if(c==1){
				ans[i]=DPt[a][b];
			}
			else {
				ans[i]=DPc[a][b];
			}
		}
		for(i=0;i<m;i++){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}