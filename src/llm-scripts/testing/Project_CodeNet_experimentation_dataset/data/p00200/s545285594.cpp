#include<iostream>
#include<algorithm>
using namespace std;
static const int INFTY = (1 << 21);
int main(){
	int t[105][105];int c[105][105];
	int n,m,a,b,cost,time,kk,p,q,r;
	while(cin >> n >> m,n,m){
		for(int i=1;i<105;i++){
			for(int j=1;j<105;j++){
				t[i][j] = c[i][j] = INFTY;
			}
		} 
		for(int i = 0;i < n;i++){
			cin >> a >> b >> cost >> time;
			t[a][b] = time;
			t[b][a] = time;
			c[a][b] = cost;
			c[b][a] = cost;
		}
		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				if(t[i][k] == INFTY) continue;
				for(int j=1;j<=m;j++){
					if(t[i][k] == INFTY) continue;
					t[i][j] = min(t[i][j],t[i][k]+t[k][j]);
					c[i][j] = min(c[i][j],c[i][k]+c[k][j]);
				}
			}
		}
		cin >>  kk;
		for(int i=0;i<kk;i++){
			cin >> p >> q >> r;
			if(r == 0) cout << c[p][q] << endl;
			else cout << t[p][q] << endl;
		}
	}
	return 0;
}