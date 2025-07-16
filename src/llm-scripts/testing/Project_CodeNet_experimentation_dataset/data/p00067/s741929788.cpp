#include <iostream>
#include <cstring>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
using namespace std;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
string fld[12];
void dfs(int x,int y){
	fld[x][y]='0';
	rep(i,4){
		int sx=x+dx[i],sy=y+dy[i];
		if(sx>=0&&sx<12&&sy>=0&&sy<12)if(fld[sx][sy]=='1')dfs(sx,sy);
	}
}
int main(){
	while(cin>>fld[0]){
		int ans=0;
		FOR(i,1,12)cin>>fld[i];
		rep(i,12)rep(j,12){
			if(fld[j][i]=='1'){
				ans++;
				dfs(j,i);
			}
		}
		cout<<ans<<endl;
	}
}