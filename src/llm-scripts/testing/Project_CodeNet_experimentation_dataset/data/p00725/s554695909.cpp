#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int a[22][22],h,w,mi;
using namespace std;
void dfs(int y,int x,int depth){
	if(depth>=mi)return;
	r(i,4){
		int y1=y,x1=x,c=0,cc=1;
		while(1){
			if(i>1){
				if(y1<0||y1>=h){c++;goto P;}
				if(cc&&i==2&&a[y1+1][x1]==1){c++;goto P;}
				if(cc&&i==3&&a[y1-1][x1]==1){c++;goto P;}
				if(y1+1<h&&i==2&&a[y1+1][x1])goto P;
				if(y1-1>=0&&i==3&&a[y1-1][x1])goto P;
			}
			else{
				if(x1<0||x1>=w){c++;goto P;}
				if(cc&&i==0&&a[y1][x1+1]==1){c++;goto P;}
				if(cc&&i==1&&a[y1][x1-1]==1){c++;goto P;}
				if(x1+1<w&&i==0&&a[y1][x1+1])goto P;
				if(x1-1>=0&&i==1&&a[y1][x1-1])goto P;
			}y1+=dy[i];x1+=dx[i];cc=0;
		}
		P:;int y2=y1+dy[i],x2=x1+dx[i];
		if(!c){if(a[y2][x2]==3||mi<depth+1){mi=depth+1;return;}
		else{
			a[y2][x2]=0;
			dfs(y1,x1,depth+1);
			a[y2][x2]=1;
		}}
	}
}
int main(){
	int hh,ww;
	while(cin>>w>>h,w){
		r(i,h)r(j,w){
			cin>>a[i][j];
			if(a[i][j]==2){
				a[i][j]=0;
				hh=i;mi=11;
				ww=j;
			}
		}
		dfs(hh,ww,0);
		if(mi==11)cout<<-1<<endl;
		else cout<<mi<<endl;
	}
}