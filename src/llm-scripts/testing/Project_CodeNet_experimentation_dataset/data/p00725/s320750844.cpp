#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;
const int MAX_W=20;
const int DIRECTIONS=4;//0:up/1:right/2:down/3:left
const int MAX_DEPTH=10;
const int INF=1<<27;

struct tpl{
  int ary[MAX_W][MAX_W];
  int depth;
  int last;
  int x;
  int y;
};

int w,h;
int dfs(const tpl& t){
  int minDepth=INF;
  if(t.depth+1>MAX_DEPTH)return minDepth;
  REP(i,DIRECTIONS){
    tpl u;
    u.depth=t.depth+1;
    u.last=i;
    REP(j,h)REP(k,w)u.ary[j][k]=t.ary[j][k];
    u.x=t.x;
    u.y=t.y;
    if(i==0&&u.y>0&&u.ary[u.y-1][u.x]!=1){
      for(;u.y>=0;u.y--){
	if(u.ary[u.y][u.x]==3){
	  minDepth=min(minDepth,u.depth);
	  break;
	}else if(u.y>0&&u.ary[u.y-1][u.x]==1){
	  u.ary[u.y-1][u.x]=0;
	  minDepth=min(minDepth,dfs(u));
	  break;
	}
      }
    }else if(i==1&&u.x<w-1&&u.ary[u.y][u.x+1]!=1){
      for(;u.x<=w-1;u.x++){
	if(u.ary[u.y][u.x]==3){
	  minDepth=min(minDepth,u.depth);
	  break;
	}else if(u.x<w-1&&u.ary[u.y][u.x+1]==1){
	  u.ary[u.y][u.x+1]=0;
	  minDepth=min(minDepth,dfs(u));
	  break;
	}
      }
    }else if(i==2&&u.y<h-1&&u.ary[u.y+1][u.x]!=1){
      for(;u.y<=h-1;u.y++){
	if(u.ary[u.y][u.x]==3){
	  minDepth=min(minDepth,u.depth);
	  break;
	}else if(u.y<h-1&&u.ary[u.y+1][u.x]==1){
	  u.ary[u.y+1][u.x]=0;
	  minDepth=min(minDepth,dfs(u));
	  break;
	}
      }
    }else if(i==3&&u.x>0&&u.ary[u.y][u.x-1]!=1){
      for(;u.x>=0;u.x--){
	if(u.ary[u.y][u.x]==3){
	  minDepth=min(minDepth,u.depth);
	  break;
	}else if(u.x>0&&u.ary[u.y][u.x-1]==1){
	  u.ary[u.y][u.x-1]=0;
	  minDepth=min(minDepth,dfs(u));
	  break;
	}
      }
    }
  }
  return minDepth;
}

void solve(const tpl& t){
  int result=dfs(t);
  cout<<(result==INF?-1:result)<<endl;
}
int main(){ _;
  while(cin>>w>>h,(w|h)!=0){
    tpl t;
    t.depth=0;
    t.last=-1;
    REP(i,h)REP(j,w){
      cin>>t.ary[i][j];
      if(t.ary[i][j]==2){
	t.ary[i][j]=0;
	t.x=j;
	t.y=i;
      }
    }
    solve(t);
  }
}