#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

int n,m;
int g[500][500];

int main(){
	while(scanf("%d%d",&n,&m),n){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++) g[i][j]=100000;
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			g[a-1][b-1]=1;g[b-1][a-1]=1;
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int k=0;k<n;k++) g[j][k]=min(g[j][k],g[j][i]+g[i][k]);
		int res=0;
		for(int i=1;i<n;i++) if(g[0][i]<=2)res++;
		printf("%d\n",res);
	}
}