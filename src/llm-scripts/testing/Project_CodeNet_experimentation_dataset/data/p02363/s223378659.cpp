#include <stdio.h>
#include <limits.h>
int main(){
	int n,m,s,i,j;
	scanf("%d%d",&n,&m);
	int e[m+1][3],dist[m+1],update=1,k,d[200][200];
	//printf("xxx");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j)d[i][j]=0;
			else d[i][j]=INT_MAX;
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<3;j++){
			scanf("%d",&e[i][j]);
		}
		d[e[i][0]][e[i][1]]=e[i][2];
	}
	for(i=0;i<n;i++){
		dist[i]=INT_MAX;
	}
	dist[s]=0;
	for(i=0;i<n-1;i++){
		update=0;
		for(j=0;j<m;j++){
			if(dist[e[j][0]]!=INT_MAX&&dist[e[j][1]]>dist[e[j][0]]+e[j][2]){
				dist[e[j][1]]=dist[e[j][0]]+e[j][2];
				update=1;
			}
		}
		if(update==0)break;
	}
	for(j=0;j<m;j++){
		if(dist[e[j][0]]!=INT_MAX&&dist[e[j][1]]>dist[e[j][0]]+e[j][2]){
			printf("NEGATIVE CYCLE\n");
			return 0;
		}
	}
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if((d[i][k]!=INT_MAX&&d[k][j]!=INT_MAX)&&d[i][j]>d[i][k]+d[k][j]){
					d[i][j]=d[i][k]+d[k][j];
				}
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j>0)printf(" ");
			if(d[i][j]==INT_MAX){
				printf("INF");
			}
			else{
				printf("%d",d[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}