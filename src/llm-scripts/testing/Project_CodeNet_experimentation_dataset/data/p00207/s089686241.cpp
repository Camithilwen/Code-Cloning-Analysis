#include <iostream>
#include <cstring>
using namespace std;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int w,h,xg,yg,xs,ys,n,fld[101][101];
bool dfs(int x,int y,int c){
	if(c==0||fld[x][y]!=c)return false;
	if(x==xg&&y==yg)return true;
	fld[x][y]=0;
	for(int i=0;i<4;i++)if(dfs(x+dx[i],y+dy[i],c))return true;
	return false;
}
int main(){
	while(cin>>w>>h,w,h){
		cin>>xs>>ys>>xg>>yg>>n;
		for(int i=0;i<n;i++){
			int x,y,cc,d,r,l;
			cin>>cc>>d>>x>>y;
			if(d){r=4;l=2;}else{r=2;l=4;}
			for(int j=x;j<x+l;j++)for(int k=y;k<y+r;k++)fld[j][k]=cc;
		}
		if(dfs(xs,ys,fld[xs][ys]))cout<<"OK"<<endl;
		else cout<<"NG"<<endl;
	}
}