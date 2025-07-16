#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int w,h;
vector<vector<int> >  b;
int sx,sy,gx,gy;
int ans;

void test(int x,int y,int n){
  int bx,by;
  int xx=x,yy=y;
  if(++n>=ans) return;

  while(b[y][x+1]==0){
    x++;
    if(x==gx&&y==gy){
      ans=n;
      return;
    }
  }
  if((x!=xx)&&(x+1!=w-1)){
    bx=x+1; by=y;
    b[by][bx]=0;
    test(x,y,n);
    b[by][bx]=1;
  }
  x=xx;y=yy;

  while(b[y][x-1]==0){
    x--;
    if(x==gx&&y==gy){
      ans=n;
      return;
    }
  }
  if(x!=xx&&x-1!=0){
    bx=x-1; by=y;
    b[by][bx]=0;
    test(x,y,n);
    b[by][bx]=1;
  }
  x=xx;y=yy;

  while(b[y+1][x]==0){
    y++;
    if(x==gx&&y==gy){
      ans=n;
      return;
    }
  }
  if(y!=yy&&y+1!=h-1){
    bx=x; by=y+1;
    b[by][bx]=0;
    test(x,y,n);
    b[by][bx]=1;
  }
  x=xx;y=yy;

  while(b[y-1][x]==0){
    y--;
    if(x==gx&&y==gy){
      ans=n;
      return;
    }
  }
  if(y!=yy&&y-1!=0){
    bx=x; by=y-1;
    b[by][bx]=0;
    test(x,y,n);
    b[by][bx]=1;
  }
  x=xx;y=yy;
}

int main(){
  while(cin>>w>>h,w+h){
    w+=2;h+=2;
    ans=11;
    b=vector<vector<int> >(h+2,vector<int>(w+2,1));
    for(int i=1;i<h-1;i++){
      for(int j=1;j<w-1;j++){
        cin >> b[i][j];
        if(b[i][j]==2){
          b[i][j]=0;
          sx=j;sy=i;
        }else if(b[i][j]==3){
          b[i][j]=0;
          gx=j;gy=i;
        }
      }
    }
    test(sx,sy,0);
    if(ans==11) cout << -1 << endl;
    else cout << ans << endl;
  }
  return 0;
}