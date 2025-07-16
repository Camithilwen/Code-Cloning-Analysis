#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <functional>
#include <set>
#include <sstream>
#include <map>
#include <queue>
#include <stack>
  
using namespace std;
 
int w,h;
int sx,sy;
int res;
int table[30][30];
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
 
void dfs(int x,int y,int cnt){
	if(cnt>=res) return ;
     
	for(int dir=0;dir<4;dir++){
		int nx=x+dx[dir],ny=y+dy[dir];
         
		if(nx<0 || w<=nx || ny<0 || h<=ny) continue;
		else if(table[ny][nx]==1) continue; 
		else if(table[ny][nx]==3){res=cnt; return;} 
         
		while(true){
			nx+=dx[dir]; ny+=dy[dir];
			if(nx<0 || w<=nx || ny<0 || h<=ny) break; 
			else if(table[ny][nx]==1){
				table[ny][nx]=0;                     
				dfs(nx-dx[dir],ny-dy[dir],cnt+1);    
				table[ny][nx]=1;        
				break;
			}else if(table[ny][nx]==3){
				res=cnt;  
				return ;
			}
		}
         
	}
     
}
 
 
int main()
{
     
	while(cin>>w>>h,w){     
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cin>>table[i][j];
				if(table[i][j]==2){sx=j;sy=i;}
			}
		}
         
		res=11;
		dfs(sx,sy,1);
		if(res>10) res=-1;
		cout<<res<<endl;
         
	}

	return 0;
}