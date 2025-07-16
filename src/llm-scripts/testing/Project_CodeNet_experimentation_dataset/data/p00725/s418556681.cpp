#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;
#define DEBUG(x) cout<<#x<<": "<<x<<endl

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define INT(a) int((a)+1e-9)
int DX[4]={1,0,-1,0};
int DY[4]={0,1,0,-1};

#define EMP 0
#define OBS 1
#define WAL 4
#define STT 2
#define GOA 3

#define SUPmaxY 22
#define SUPmaxX 22

int maxY,maxX;
int field[SUPmaxX][SUPmaxY];
int startX,startY;
int result;


int dfs(int x, int y, int depth){
	//DEBUG(x);DEBUG(y);DEBUG(depth);
	if(depth>=result) return 0;
	if(field[x][y]==GOA) {result=depth; return 0;}
	
	FOR(di,0,4){
		int nx=x; int ny=y;
		int dx=DX[di]; int dy=DY[di];
		if(field[x+dx][y+dy]==OBS) continue;
		while(field[nx][ny]==EMP){
			nx+=dx;ny+=dy;
		}
		if(field[nx][ny]==WAL){continue;}
		if(field[nx][ny]==GOA){result=depth+1; return 0;}
		if(field[nx][ny]==OBS){
			field[nx][ny]=EMP;
			dfs(nx-dx,ny-dy,depth+1);
			field[nx][ny]=OBS;
		}
	}
	

}



int main(){
	while(true){
		cin>>maxY>>maxX;			if(!maxY) return 0;
		maxX+=2;maxY+=2;
		FOR(x,0,maxX) FOR(y,0,maxY) field[x][y]=WAL;
		FOR(x,1,maxX-1) FOR(y,1,maxY-1) cin>>field[x][y];
		FOR(x,1,maxX-1) FOR(y,1,maxY-1) if(field[x][y]==STT){startX=x;startY=y;field[x][y]=EMP;}

		result=11;
		dfs(startX,startY,0);
		cout<< ((result==11)?-1:result) <<endl;
	}
}