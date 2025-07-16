#include <iostream>
using namespace std;

int fld[100][100];//[横][縦]
int Dx[4]={0,-1,0,1};
int Dy[4]={1,0,-1,0};

bool ans[1000];
int counter=0;

bool flag=true;

void dfs(int x,int y,int w,int h,int c){//スタート地点と色を与える
	fld[x][y]=-1;
	for(int i=0;i<4;i++){
		int nx=x+Dx[i],ny=y+Dy[i];//範囲内にある必要あり
		if(nx>=0 && nx<w && ny>=0 && ny<h){
		if(fld[nx][ny]==c)//同色についてのみ継続
			dfs(nx,ny,w,h,c);
		}
	}
}//色の塗り替え
	

void solve(){
	int w,h,xs,ys,xg,yg,n;
	cin >> w>>h;
	
	if(w==0) {flag=false;counter--; return;}
	
	cin >>xs>>ys>>xg>>yg>>n;//start,goal座標は-1する
	xs--;ys--;xg--;yg--;
	
	for(int i=0;i<w;i++){//fieldの初期化0~w-1
		for(int j=0;j<h;j++){//0~h-1
			fld[i][j]=0;//0は何も無い
		}
	}
	
	for(int i=0;i<n;i++){
		int color,drc,x,y;
		cin >>color>>drc>>x>>y;
		x--;y--;
		if(drc==0){
			for(int dx=0;dx<4;dx++){
				for(int dy=0;dy<2;dy++){
					fld[x+dx][y+dy]=color;
				}
			}
		}
		if(drc==1){
			for(int dy=0;dy<4;dy++){
				for(int dx=0;dx<2;dx++){
					fld[x+dx][y+dy]=color;
				}
			}
		}
	}//fieldの色塗り
	
	if(fld[xs][ys]!=fld[xg][yg]) {
		ans[counter]=false;
		return;
	}
	if(fld[xs][ys]==0){
		ans[counter]=false;
		return;
	}
	
	dfs(xs,ys,w,h,fld[xs][ys]);//塗り替え
	
	if(fld[xg][yg]==-1) ans[counter]=true;
	else ans[counter]=false;
	
	return;
}

int main(){
	while(flag){
		solve();
		counter++;
	}
	for(int i=0;i<counter;i++){
		if(ans[i]) cout << "OK"<<endl;
		else cout << "NG" << endl;
	}
	
}