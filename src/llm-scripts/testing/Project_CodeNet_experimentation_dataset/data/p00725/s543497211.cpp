#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;
const int INF=11;

int w,h;

int field[22][22];
int sx,sy;
int gx,gy;
int ans=INF;
int hx[4]={1,-1,0,0,},hy[4]={0,0,1,-1,};

void dfs(int field2[22][22],int x,int y,int mx,int my,int c){
	int a;
	if(c>10)return;
	if(c>ans)return;
	if(x>0 && x<=w && y>0 && y<=h);else return; 
	if(field2[x][y]==3){
		if(ans>c)ans=c;
		return;
	}
	if(field2[x+mx][y+my]==1){
		field2[x+mx][y+my]=0;
		for(a=0;a<4;a++){
			if(field2[x+hx[a]][y+hy[a]]!=1)dfs(field2,x,y,hx[a],hy[a],c+1);
		}
		field2[x+mx][y+my]=1;
	}else dfs(field2,x+mx,y+my,mx,my,c);
	return;
}

int main(void){
	int a,b;
	while(1){
		for(b=0;b<21;b++){
			for(a=0;a<21;a++){
				field[a][b]=0;
			}
		}
		ans=INF;
		sx=0;
		sy=0;
		gx=0;
		gy=0;
		cin >> w >> h;
		if(w==0 && h==0)break;
		for(b=1;b<=h;b++){
			for(a=1;a<=w;a++){
				cin >> field[a][b];
				if(field[a][b]==2)sx=a,sy=b,field[a][b]=0;
				if(field[a][b]==3)gx=a,gy=b;
				
			}
		}
		for(a=0;a<4;a++){
			if(field[sx+hx[a]][sy+hy[a]]!=1)dfs(field,sx,sy,hx[a],hy[a],1);
		}
		printf("%d\n",ans<=10?ans:-1);
	}
	return 0;
}