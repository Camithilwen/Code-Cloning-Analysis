#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#define MOD 1000000007
typedef long long ll;
using namespace std;

vector<pair<int,int>> v[100010];
ll dist[100010];
const ll INF=1e10;
vector<set<int>> s(100010);

void dijkstra(){
  priority_queue<pair<ll,int>> PQ;
  //priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> PQ;
  for(int i=0;i<=100005;i++) dist[i]=INF;
  PQ.push(make_pair(0,1));
  dist[1]=0;

  while(!PQ.empty()){
    pair<ll,int> f=PQ.top();
    PQ.pop();
    int t=f.second;

    if(dist[t]<-f.first) continue;

    for(int i=0;i<v[t].size();i++){
      pair<int,int> u=v[t][i];
      ll c=0;
      if(s[t].count(u.second)==0) c++;

      if(dist[u.first]>dist[t]+c){
        s[u.first].clear();
        s[u.first].insert(u.second);
        dist[u.first]=dist[t]+c;
        PQ.push(make_pair(-dist[u.first],u.first));
      }else if(dist[u.first]==dist[t]+c){
        if(s[u.first].count(u.second)==0){
          s[u.first].insert(u.second);
          //PQ.push(make_pair(dist[u.first],u.first));
        }
        //s[u.first].insert(u.second);
      }
      //cout<<u.first<<" "<<u.second<<" "<<dist[u.first]<<endl;
    }
  }

  return;
}

int main(){
  int n,m;
  cin>>n>>m;

  for(int i=0;i<m;i++){
    int p,q,c;
    scanf("%d %d %d",&p,&q,&c);
    v[p].push_back(make_pair(q,c));
    v[q].push_back(make_pair(p,c));
  }

  dijkstra();

  //for(int i=0;i<n;i++) cout<<i+1<<" "<<dist[i+1]<<endl;

  if(dist[n]==INF) cout<<-1<<endl;
  else cout<<dist[n]<<endl;


  return 0;
}
