#include<stdio.h>
#define INF 1000000
void warshall_floyd();
int min(int,int);
int graph[101][101],n,c,d;

int main(){
  int k,i,j,x,e,a,b;

  while(scanf("%d %d",&n,&k),n,k){

    for(i=0;i<=n;i++)
      for(j=0;j<=n;j++)
	graph[i][j]=i==j?0:INF;

    for(i=0;i<k;i++){

      if(scanf("%d",&x),x){
	scanf("%d %d %d",&c,&d,&e);

	if(graph[c][d]>e){
	graph[c][d]=graph[d][c]=e;
	warshall_floyd();
	}
      }else{
	scanf("%d %d",&a,&b);
	printf(graph[a][b]>=INF?"-1\n":"%d\n",graph[a][b]);
      }
    }
  }
  return 0;
}

void warshall_floyd(){
  int i,j;
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      graph[i][j]=graph[j][i]=min(graph[i][j],graph[i][c]+graph[c][d]+graph[d][j]);
}

int min(int x,int y){
  return x<y?x:y;
}