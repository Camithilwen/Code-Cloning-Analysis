#include <cstdio>
#include <algorithm>
using namespace std;
#define INF (1<<27)
int cost[100][100];
int main() {
	int n,k;
	while(scanf("%d %d",&n,&k),n) {
		fill((int*)cost,(int*)(cost+100),INF);
		for(int i=0;i<k;i++) {
			int a,b,c;
			scanf("%d",&a);
			if(a==0) {
				scanf("%d %d",&a,&b);
				if(cost[a-1][b-1]==INF)
					printf("-1\n");
				else
					printf("%d\n",cost[a-1][b-1]);
			}else {
				scanf("%d %d %d",&a,&b,&c);
				if(cost[a-1][b-1]>c) {
					cost[a-1][b-1]=cost[b-1][a-1]=c;
					for(int k=0;k<n;k++) {
						for(int i=0;i<n;i++) {
							for(int j=0;j<n;j++) {
								cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
							}
						}
					}
				}
			}
		}
	}
}