#include "bits/stdc++.h"
using namespace std;

#define INF 1e9+7

int main(){
	int n,m;
	while(1){
		cin>>n>>m;
		if(n==0&&m==0)break;
		vector<vector<int> > cost(m,vector<int>(m,INF));
		vector<vector<int> > timea(m,vector<int>(m,INF));
		
		for(int i=0;i<n;i++){
			int a,b;
			cin>>a>>b;
			a--;
			b--;
			cin>>cost[a][b]>>timea[a][b];
			cost[b][a]=cost[a][b];
			timea[b][a]=timea[a][b];
		}
		
		for(int i=0;i<m;i++){
			cost[i][i]=0;
			timea[i][i]=0;
		}
		
		for(int k=0;k<m;k++){
			for(int i=0;i<m;i++){
				for(int j=0;j<m;j++){
					cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
					timea[i][j]=min(timea[i][j],timea[i][k]+timea[k][j]);
				}
			}
		}
		
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			int p,q,r;
			cin>>p>>q>>r;
			p--;
			q--;
			if(r==0)cout<<cost[p][q]<<endl;
			if(r==1)cout<<timea[p][q]<<endl;
		}
	}
	return 0;
}