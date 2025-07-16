#include<bits/stdc++.h>
#define ri register int
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> poly;
#define pb push_back
#define fi first
#define se second
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read() {
  int ans=0;
  char ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return ans;
}
char c3[3][3]={
  {'.','.','a'},
  {'.','.','a'},
  {'a','a','.'}
};
char c4[4][4]={
  {'a','b','e','e'},
  {'a','b','f','f'},
  {'c','c','g','h'},
  {'d','d','g','h'}
};
char c5[5][5]={
  {'a','a','b','b','a'},
  {'b','c','c','.','a'},
  {'b','.','.','c','b'},
  {'a','.','.','c','b'},
  {'a','b','b','a','a'}
};
char c7[7][7]={
  {'a','.','a','a','.','a','a'},
  {'a','b','.','.','b','b','.'},
  {'.','b','.','a','a','.','a'},
  {'a','.','a','.','.','.','a'},
  {'a','.','a','.','.','b','.'},
  {'.','b','b','.','.','b','a'},
  {'a','a','.','a','a','.','a'}
};
int n;
char ans[1005][1005];
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  cin>>n;
  if(n<3) puts("-1");
  else {
    for(ri i=1;i<=n;++i) for(ri j=1;j<=n;++j) ans[i][j]='.';
    if(n%3==0) {
      for(ri i=1;i<=n;i+=3) for(ri dx=0;dx<3;++dx)
      for(ri dy=0;dy<3;++dy)ans[i+dx][i+dy]=c3[dx][dy];
    }
    else {
      int x=-1,y=-1,z=-1;
      for(ri i=0;i*4<=n&&x==-1;++i) for(ri j=0;i*4+j*5<=n;++j) if((n-i*4-j*5)%7==0) {
        x=i,y=j,z=(n-i*4-j*5)/7;
        break;
      }
      int ps=1;
      while(x--) {
        for(ri dx=0;dx<4;++dx) for(ri dy=0;dy<4;++dy) ans[ps+dx][ps+dy]=c4[dx][dy];
        ps+=4;
      }
      while(y--) {
        for(ri dx=0;dx<5;++dx) for(ri dy=0;dy<5;++dy) ans[ps+dx][ps+dy]=c5[dx][dy];
        ps+=5;
      }
      while(z--) {
        for(ri dx=0;dx<7;++dx) for(ri dy=0;dy<7;++dy) ans[ps+dx][ps+dy]=c7[dx][dy];
        ps+=7;
      }
    }
    for(ri i=1;i<=n;++i,puts("")) for(ri j=1;j<=n;++j) cout<<ans[i][j];
  }
  return 0;
}