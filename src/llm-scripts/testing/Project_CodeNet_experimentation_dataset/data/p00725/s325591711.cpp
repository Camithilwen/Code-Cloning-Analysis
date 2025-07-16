#include <iostream>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <complex>
#include <cstdio>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int w,h,m[21][21],sx,sy,gx,gy,dx[]={1,0,-1,0},dy[]={0,1,0,-1};

int f(int w,int h,int m[][21],int x,int y,int t){
	if(t==10)return 99;
	int res=99;
	rep(i,4){
		int cx=x,cy=y,d=0;
		while(1){
			cx+=dx[i];cy+=dy[i];
			if(cx<0||cx>=w||cy<0||cy>=h)break;
			if(m[cy][cx]==3){res=min(res,t+1);break;}
			if(m[cy][cx]==1){
				if(!d)break;
				int m2[21][21];
				rep(j,h)rep(k,w)m2[j][k]=m[j][k];
				m2[cy][cx]=0;
				res=min(res,f(w,h,m2,cx-dx[i],cy-dy[i],t+1));
				break;
			}
			d++;
		}
	}
	return res;
}

int main(){
	while(cin>>w>>h&&w){
		rep(i,h)rep(j,w){
			cin>>m[i][j];
			if(m[i][j]==2){sx=j,sy=i;}
			if(m[i][j]==3){gx=j,gy=i;}
		}
		int ans=f(w,h,m,sx,sy,0);
		cout<<(ans<99?ans:-1)<<endl;
	}
}