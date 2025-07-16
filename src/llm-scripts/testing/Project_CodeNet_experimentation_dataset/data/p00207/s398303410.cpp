#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
int w,h,xs,ys,xg,yg,n;
int m[102][102];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool DFS(int x,int y,int c){
  if(m[x][y]!=c)return false;
  if(x==xg && y == yg)return true;
  m[x][y]=-1;
  bool ans =false;
  rep(i,0,4){
    ans = max(ans,DFS(x+dx[i],y+dy[i],c));
  }
  return ans;
}
int main(){
  cin >>w>>h;
  while(w!=0){
    cin>>xs>>ys>>xg>>yg>>n;
    xs++;
    ys++;
    xg++;
    yg++;
    rep(i,0,102)rep(j,0,102)m[i][j]=-1;
    rep(i,0,n){
      int c,d,x,y;
      cin >>c>>d>>x>>y;
      x++;
      y++;
      if(d==0){
        rep(j,x,x+4)rep(k,y,y+2)m[j][k]=c;
      }else{
        rep(j,x,x+2)rep(k,y,y+4)m[j][k]=c;
      }
    }
    string ans[2]={"NG","OK"};
    if(m[xs][ys]==-1)cout <<"NG"<<endl;
    else cout << ans[DFS(xs,ys,m[xs][ys])]<<endl;
    cin >> w>>h;
  }
  return 0;
}

