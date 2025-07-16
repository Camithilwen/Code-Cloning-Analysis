#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int N,K;

int ans[100010];
vector<int> g[100010];
bool used[100010];
int dist[100010];

vector<int> rg[100010];

void dfs(int now,int len){
    used[now]=true;
    dist[now]=len;
    for(int i=0;i<g[now].size();i++){
        int next=g[now][i];
        if(used[next]) continue;

        dfs(next,len+1);
    }
    return;
}

int rdfs(int now,int len){
    used[now]=true;
    if(len==K-1) return now;
    for(int i=0;i<rg[now].size();i++){
        int next=rg[now][i];
        if(used[next]) continue;

        return rdfs(next,len+1);
    }
    return -1;
}

void visit(int now){
    used[now]=true;
    for(int i=0;i<g[now].size();i++){
        int next=g[now][i];
        if(used[next]) continue;

        if(dist[next]>dist[now]) visit(next);
    }
    return;
}

int main(){
  cin>>N>>K;
  int a[N+1]={};
  for(int i=0;i<N;i++){
      cin>>a[i];
      a[i]--;
      ans[i]=a[i];
      if(i>0){
          g[a[i]].push_back(i);
          rg[i].push_back(a[i]);
      }
  }
  ans[0]=0;

  dfs(0,0);

  priority_queue<pair<int,int>> PQ;
  for(int i=0;i<N;i++){
      used[i]=false;
      PQ.push(make_pair(dist[i],i));
  }
  while(!PQ.empty()){
      pair<int,int> tp=PQ.top();
      PQ.pop();
      int now=tp.second;
      if(used[now]) continue;

      int x=rdfs(now,0);
      if(x!=-1){
          ans[x]=0;
          visit(x);
      }
  }

  int res=0;
  for(int i=0;i<N;i++){
      if(ans[i]!=a[i]) res++;
  }
  cout<<res<<endl;


  return 0;
}
