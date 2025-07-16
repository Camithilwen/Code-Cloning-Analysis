#include<iostream>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

int color[200][200];
bool flg[200][200];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int w,h,n,c,d,x,y;

void dfs(int ny,int nx,int gy,int gx){
	flg[ny][nx]=true;
	rep(i,4){
		int nex=nx+dx[i];
		int ney=ny+dy[i];
		if(nex>=w || nex<0 || ney>=h || ney<0)continue;
		if(color[ney][nex]==color[ny][nx] && flg[ney][nex]==false)dfs(ney,nex,gy,gx);
	}
	return;
}

int main(){
	pair<int,int> s,g;
	while(1){
		rep(i,200)rep(j,200)color[i][j]=flg[i][j]=0;
		cin>>w>>h;
		if(w==0 && h==0)break;
		cin>>s.first>>s.second;
		cin>>g.first>>g.second;
		cin>>n;
		rep(i,n){
			cin>>c>>d>>x>>y;
			if(d==0){
				rep(j,2){
					rep(k,4){
						color[y-1+j][x-1+k]=c;
					}
				}
			}else{
				rep(j,4){
					rep(k,2){
						color[y-1+j][x-1+k]=c;
					}
				}
			}
		}
		dfs(s.second-1,s.first-1,g.second-1,g.first-1);
		if(flg[g.second-1][g.first-1])cout<<"OK"<<endl;
		else cout<<"NG"<<endl;
	}
	return 0;
}