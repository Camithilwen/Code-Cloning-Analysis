#include<cstdio>
#include<algorithm>
#include<cstring>

int main(){
	using namespace std;
	int table[300][300][2],n,m,a,b,INF=10000000;
	while(true){
		scanf("%d%d",&n,&m);
		if(n==0&&m==0) break;
		for(int i=0;i<300;i++)
			for(int j=0;j<300;j++)
				for(int k=0;k<2;k++)
					table[i][j][k]=INF;
		for(int i=0;i<300;i++){
			table[i][i][0]=0;
			table[i][i][1]=0;
		}
		while(n--){
			scanf("%d%d",&a,&b);
			scanf("%d",&table[a-1][b-1][0]);
			table[b-1][a-1][0]=table[a-1][b-1][0];
			scanf("%d",&table[a-1][b-1][1]);
			table[b-1][a-1][1]=table[a-1][b-1][1];
		}

		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				for(int k=0;k<m;k++){
					table[j][k][0]=min(table[j][k][0],table[j][i][0]+table[i][k][0]);
					table[j][k][1]=min(table[j][k][1],table[j][i][1]+table[i][k][1]);
				}
			}
		}
		scanf("%d",&m);
		while(m--){
			scanf("%d%d%d",&a,&b,&n);
			printf("%d\n",table[a-1][b-1][n]);
		}
	}	
	return 0;

}