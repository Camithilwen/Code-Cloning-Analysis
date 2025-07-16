#include <stdio.h>
#include <algorithm>
#define INF 100000000
using namespace std;

int n;
int graph[100][100];

void floyd(){
    for(int k=0;k<n;k++)
      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
}


int main(){
  int k,i,j,a,b,c,d,e,x;
  while(scanf("%d %d",&n,&k),n,k){
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
        graph[i][j]=i==j?0:INF;
    for(i=0;i<k;i++){
      if (scanf("%d",&x),x){
        scanf("%d %d %d",&c,&d,&e);
        if (graph[--c][--d]>e){
          graph[c][d]=graph[d][c]=e;
          floyd();
        }
      }else{
        scanf("%d %d",&a,&b);
        if (graph[--a][--b]==INF)
          printf("-1\n");
        else
          printf("%d\n",graph[a][b]);
      }
    }
  }
  return 0;
}