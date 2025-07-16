#include <iostream>
using namespace std;

#define INF 10000000

int t[101][101], s[101][101];

int main(void){
	int n,m;

	while(cin>>n>>m, n){
		for(int i=0;i<=m;i++) for(int j=0;j<=m;j++) t[i][j] = s[i][j] = INF;
		for(int i=0;i<n;i++){
			int a,b,cost,time;
			cin>>a>>b>>cost>>time;
			t[a][b] = t[b][a] = cost;
			s[a][b] = s[b][a] = time;
		}

		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					t[i][j] = min(t[i][j],t[i][k]+t[k][j]);
					s[i][j] = min(s[i][j],s[i][k]+s[k][j]);
				}
			}
		}

		cin>>n;
		while(n--){
			int a,b,flg;
			cin>>a>>b>>flg;
			cout<<(flg?s[a][b]:t[a][b])<<endl;
		}
	}

	return 0;
}