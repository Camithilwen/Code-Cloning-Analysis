#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<cstdio>
#include<sstream>
#include<iomanip>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef pair<int,pii> pip;
typedef vector<pip>vip	;
const double PI=acos(-1);
const double EPS=1e-8;
const int inf=1e8;
int n,m;
vvi in;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int out;
void f(int x,int y,int c){
	if(c==10)return;
	rep(i,4){
		int nx=x,ny=y;
//		cout<<nx<<" "<<ny<<endl;
		while(1){
			nx+=dx[i];ny+=dy[i];
			if(nx<0||ny<0||nx>=n||ny>=m)break;
			if(in[x+dx[i]][y+dy[i]]==1)break;
			if(in[nx][ny]==3){
				out=min(out,c+1);
				return;
			}
			if(in[nx][ny]==1){
				in[nx][ny]=0;
				f(nx-dx[i],ny-dy[i],c+1);
				in[nx][ny]=1;
				break;
			}
		}
	}
}
int main(){
	while(cin>>m>>n,n+m){
		out=inf;
		in=vvi(n,vi(m));
		rep(i,n)rep(j,m)cin>>in[i][j];
		rep(i,n)rep(j,m)if(in[i][j]==2){
			f(i,j,0);
			if(out!=inf)cout<<out<<endl;
			else cout<<-1<<endl;
			goto end;
		}
		end:;
	}
}