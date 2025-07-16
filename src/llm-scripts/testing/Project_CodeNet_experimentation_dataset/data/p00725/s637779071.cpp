#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define HMAX 20
#define WMAX 20
using namespace std;

int w,h;

int dd[5]={0,1,0,-1,0};

void dfs_aux(int sx, int sy, int map[WMAX][HMAX],int *min,int count){
  rep(r,4){
    int nx=sx,ny=sy;
    if(map[nx+dd[r]][ny+dd[r+1]]==1)
      continue;
    while(0<=nx+dd[r] && nx+dd[r]<w && 0<=ny+dd[r+1] && ny+dd[r+1]<h){
      nx+=dd[r];
      ny+=dd[r+1];
      if(map[nx][ny]==3)
	if(*min > count){
	  *min = count;
	  break;
	}
      if(map[nx][ny]==1){
	break;
      }
    }
    
    if(map[nx][ny]==1 && count <10){
      map[nx][ny]=0;
      nx-=dd[r];ny-=dd[r+1];
      dfs_aux(nx,ny,map,min,count+1);
      nx+=dd[r];ny+=dd[r+1];
      map[nx][ny]=1;
    }
  }
}  

int dfs(int sx, int sy, int map[WMAX][HMAX]){
  int min=11;
  dfs_aux(sx,sy,map,&min,1);
  if(min>10)
    return -1;
  return min;
}

int main(){
  for(;;){
    scanf("%d %d",&w,&h);
    if(!(w+h)) break;
    int map[WMAX][HMAX],sx,sy;
    rep(i,h){
      rep(j,w){
	scanf("%d",&map[j][i]);
	if(map[j][i]==2){
	  sx=j;
	  sy=i;
	}
      }
    }
    printf("%d\n",dfs(sx,sy,map));
  }
}