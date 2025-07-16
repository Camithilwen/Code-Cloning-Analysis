#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
const int MOD=1e9+7;
//const int MOD=998244353;
const long long LINF=1e18;
#define int long long
//template
/*
問題の言い換え
//0の行き先が0じゃなかったら0にしてans++;
0を根とする根付き木を考える
各部分根付き木の深さが(根の深さを0として）K以下になるように分解するとき最小でいくつに分解しないといけないか
これは葉から決めていけばよさそう
*/
//main
signed main(){
  int N,K,ans=0;cin>>N>>K;
  std::vector<int> v(N),in(N,0),depth(N,1);;
  for(int i=0;i<N;i++)cin>>v[i],v[i]--;
  if(v[0])ans++;v[0]=0;
  for(int i=0;i<N;i++)in[v[i]]++;
  queue<int> que;
  for(int i=0;i<N;i++)if(!in[i])que.push(i);
  while(que.size()){
    int p=que.front();que.pop();if(p==0)continue;
    if(depth[p]==K&&v[p])depth[p]=0,ans++;
    depth[v[p]]=max(depth[v[p]],depth[p]+1);
    if(!--in[v[p]])que.push(v[p]);
  }
  cout<<ans<<endl;
}
