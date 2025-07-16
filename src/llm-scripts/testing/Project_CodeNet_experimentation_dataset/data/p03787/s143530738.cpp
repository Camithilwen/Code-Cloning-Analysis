#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define int ll
vector<ll> node[100005];
ll group[100005]={0},group_num[100005]={0},col[100005]={0};
ll nibu[100005]={0};
bool used[100005]={0};
bool dfs(ll pos,ll k,ll cl){
  used[pos]=true;
  group[pos]=k;
  col[pos]=cl;
  ll nc=cl%2;
  nc++;
  bool res=true;
  for(int i=0;i<node[pos].size();i++){
    ll to=node[pos][i];
    if(!used[to]){
      used[to]=true;
      dfs(to,k,nc);
    }
    if(col[to]!=nc){
      res=false;
    }
  }
  return res;
}
signed main(){
  ll n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    ll s,t;
    cin>>s>>t;
    node[s].push_back(t);
    node[t].push_back(s);
  }
  for(int i=1;i<=n;i++) used[i]=false;
  ll cnct_num=0,a=0,b=0,c=0;
  for(int i=1;i<=n;i++){
    if(!used[i]){
      used[i]=true;
      group[i]=cnct_num;
      if(node[i].size()==0) {
        c++;
        continue;
      }
      bool f=dfs(i,cnct_num,1);
      b++;
      cnct_num++;
    }
  }
 for(int i=1;i<=n;i++){
    for(int j=0;j<node[i].size();j++){
      ll to=node[i][j];
      if(col[i]==col[to]){
        nibu[group[i]]=1;
      }
    }
  }
  for(int i=0;i<cnct_num;i++){
    if(nibu[i]==1){
      b--;
      a++;
    }
  }
  cout<<a*a+2*a*b+2*b*b+c*(n*2-c)<<endl;
}
