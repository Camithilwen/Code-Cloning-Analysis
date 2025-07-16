#include<bits/stdc++.h>
using namespace std;
int N,M;

int main()
{
	while(true){
		scanf("%d%d",&N,&M);
		if(N==0&&M==0)return 0;
		int cost[200][200];
		int time[200][200];
		int minc[200][200];
		int mint[200][200];
		for(int i=0;i<M;i++){
			for(int j=0;j<M;j++){
				cost[i][j]=1<<25;
				time[i][j]=1<<25;
				minc[i][j]=1<<25;
				mint[i][j]=1<<25;
				if(i==j){
					cost[i][j]=0;
					time[i][j]=0;
					minc[i][j]=0;
					mint[i][j]=0;
				}
			}
		}
		int A,B,co,ti;
		for(int i=0;i<N;i++){
			scanf("%d%d%d%d",&A,&B,&co,&ti);A--;B--;
			cost[A][B]=co;cost[B][A]=co;
			time[A][B]=ti;time[B][A]=ti;
		}
		for(int i=0;i<M;i++){
			for(int j=0;j<M;j++){
				for(int k=0;k<M;k++){
					cost[j][k]=min(cost[j][k],cost[j][i]+cost[i][k]);
					time[j][k]=min(time[j][k],time[j][i]+time[i][k]);
				}
			}
		}
		
		int K;
		scanf("%d",&K);
		for(int i=0;i<K;i++){
			int P,Q,R;
			scanf("%d%d%d",&P,&Q,&R);P--;Q--;
			if(R==0)printf("%d\n",cost[P][Q]);
			else printf("%d\n",time[P][Q]);
		}
	}
}