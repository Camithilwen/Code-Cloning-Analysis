#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
const int INF=1e9;
//const int MOD=998244353;
const long long LINF=1e18;
#define int long long
//template
int black[2005][2005],ver[2005][2005],wid[2005][2005];
//main
signed main(){
  int N,M,Q;cin>>N>>M>>Q;
  std::vector<string> s(N+1);
  for(int i=0;i<N;i++)cin>>s[i];
  s[N]=(string(M,'#'));
  for(int i=0;i<=N;i++)s[i]+="#";
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(s[i][j]=='1')black[i+1][j+1]++;
      if(s[i][j]=='1'&&s[i][j+1]=='1')ver[i+1][j+1]++;
      if(s[i][j]=='1'&&s[i+1][j]=='1')wid[i+1][j+1]++;
    }
  }
  for(int i=0;i<=N;i++){
    for(int j=0;j<=M;j++){
      black[i][j+1]+=black[i][j];
      ver[i][j+1]+=ver[i][j];
      wid[i][j+1]+=wid[i][j];
    }
  }
  for(int i=0;i<=N;i++){
    for(int j=0;j<=M;j++){
      black[i+1][j]+=black[i][j];
      ver[i+1][j]+=ver[i][j];
      wid[i+1][j]+=wid[i][j];
    }
  }
  std::vector<int> ans(Q);
  for(int i=0;i<Q;i++){
    int x1,x2,y1,y2;cin>>x1>>y1>>x2>>y2;
    int B=black[x2][y2]+black[x1-1][y1-1]-black[x2][y1-1]-black[x1-1][y2];
    int E1=ver[x2][y2-1]+ver[x1-1][y1-1]-ver[x2][y1-1]-ver[x1-1][y2-1];
    int E2=wid[x2-1][y2]+wid[x1-1][y1-1]-wid[x2-1][y1-1]-wid[x1-1][y2];
    ans[i]=B-E1-E2;
  }
  for(int i=0;i<Q;i++)cout<<ans[i]<<endl;
}
/*
解説AC
連結成分の個数は森なら頂点の個数と辺の数から数えられるというもの
森じゃなくても各連結成分の頂点の数と辺の数に何かしら関係があれば使えるテクだね
数えやすい成分に言い換えてしまうテクニック
あとそもそも今回の問題の設定を閉路がないとしか思わなかったけど閉路がない＝木（森）を忘れていた
*/
