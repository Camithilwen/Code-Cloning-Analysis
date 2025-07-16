#include<bits/stdc++.h>
using namespace std;
pair<int,int> pii;

int main() {
	int w,h,n;
	int xs,ys;
	int xg,yg;
	int c,d,x,y;
	int v[101][101];
	int u[101][101];
	int flag=0;
	int xx[4]={-1,0,1,0};
	int yy[4]={0,1,0,-1};
	int xxx,yyy;
while(cin>>w>>h,w||h){
	cin>>xs>>ys;
	cin>>xg>>yg;
	cin>>n;
	fill(v[0],v[101],0);
	fill(u[0],u[101],0);
	for (int i = 0; i < n; ++i) {
			cin>>c>>d>>x>>y;
			if(d==0){
				v[x][y]=c;	v[x+1][y]=c;	v[x+2][y]=c;	v[x+3][y]=c;
				v[x][y+1]=c;	v[x+1][y+1]=c;	v[x+2][y+1]=c;	v[x+3][y+1]=c;
			}
			if(d==1){
				v[x][y]=c;	v[x][y+1]=c;	v[x][y+2]=c;	v[x][y+3]=c;
				v[x+1][y]=c;	v[x+1][y+1]=c;	v[x+1][y+2]=c;	v[x+1][y+3]=c;
			}
	}
	queue<pair<int,int> > q;
	u[xs][ys]=1;
	int color=v[xs][ys];
	q.push(make_pair(xs,ys));
	while(!q.empty()){
		pii=q.front();q.pop();
		if(pii.first==xg&&pii.second==yg){flag=1;break;}
		for (int i = 0; i < 4; ++i) {
			xxx=xx[i]+pii.first;
			yyy=yy[i]+pii.second;
			if(xxx>=1&&xxx<=w&&yyy>=1&&yyy<=h&&u[xxx][yyy]!=1&&color==v[xxx][yyy]){
				u[xxx][yyy]=1;
				q.push(make_pair(xxx,yyy));
			}
		}
	}
	if(flag){cout<<"OK"<<endl;}
	else{cout<<"NG"<<endl;}
	flag=0;
}
	return 0;
}