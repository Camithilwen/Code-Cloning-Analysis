#include<iostream>
using namespace std;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int t[200][200],vd[200][200];
int W,H,sx,sy,gx,gy,n,key;

bool inField(int y,int x){
  if(y<0||y>=H)return false;
  if(x<0||x>=W)return false;
  return true;
}

bool solve(int y,int x){
  if(y==gy&&x==gx)return true;
  for(int i=0;i<4;i++){
    int ny=y+dy[i],nx=x+dx[i];
    if(!inField(ny,nx))continue;
    if(t[ny][nx]!=key)continue;
    if(vd[ny][nx]==1)continue;
    vd[ny][nx]=1;
    if( solve(ny,nx) ) return true;
  }
  return false;
}

void init(){
  for(int i=0;i<200;i++)
    for(int j=0;j<200;j++)
      t[i][j]=vd[i][j]=-1;
}

int main(){
  int a,b,x,y;
  while(cin>>W>>H){
    if(W==0&&H==0)break;
    init();
    cin>>sx>>sy>>gx>>gy>>n;
    sx--,sy--,gx--,gy--;
    for(int k=0;k<n;k++){
      cin>>a>>b>>x>>y;
      x--,y--;
      for(int i=0;i<(b==0?2:4);i++)
	for(int j=0;j<(b==0?4:2);j++)
	  t[y+i][x+j]=a;
    }
    key=t[sy][sx];
    cout<<(key!=-1&&solve(sy,sx)?"OK":"NG")<<endl;
  }
  return 0;
}