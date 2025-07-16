#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#define INF 1000000
void cWarshall_Floyd();
void tWarshall_Floyd();
int glid_cost[101][101];
int glid_tim[101][101];
int n,m,a,b,tim,cost,qs,p,q,r;
using namespace std;
void cWarshall_Floyd()
{
	int i,j,k;
	for(k=0;k<m;k++) {
		for(i=0;i<m;i++) {
			for(j=0;j<m;j++) {
				glid_cost[i][j]=min(glid_cost[i][j],glid_cost[i][k]+glid_cost[k][j]);
			}
		}
	}
}
void tWarshall_Floyd()
{
	int i,j,k;
	for(k=0;k<m;k++) {
		for(i=0;i<m;i++) {
			for(j=0;j<m;j++) {
				glid_tim[i][j]=min(glid_tim[i][j],glid_tim[i][k]+glid_tim[k][j]);
			}
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	int i,j,k;
	while(1) {
		cin>>n>>m;
		if(n==0&&m==0) break;
		for(i=0;i<m;i++) {
			for(j=0;j<m;j++) {
				glid_cost[i][j]=INF;
				glid_tim[i][j]=INF;
			}
		}
		for(i=0;i<m;i++) {
			glid_cost[i][i]=0;
			glid_tim[i][j]=0;
		}
		for(i=0;i<n;i++) {
			cin>>a>>b>>cost>>tim;
			a--;b--;
			glid_cost[a][b]=cost;
			glid_cost[b][a]=cost;
			glid_tim[a][b]=tim;
			glid_tim[b][a]=tim;
		}
		cWarshall_Floyd();
		tWarshall_Floyd();
		cin>>qs;
		for(i=0;i<qs;i++) {
			cin>>p>>q>>r;
			p--;q--;
			if(r==0) cout<<glid_cost[p][q]<<endl;
			else cout<<glid_tim[p][q]<<endl;
		}
	}
	return 0;
}