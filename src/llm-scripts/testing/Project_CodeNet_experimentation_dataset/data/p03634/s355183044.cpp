#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

struct edge{
  ll to, cost;
};

int main()
{
  ll N;
  cin >> N;
  vector<vector<ll>> A(N-1,vector<ll>(3));
  vector<vector<edge>> vec(N,vector<edge> ());
  REP(i, N-1){
    REP(j, 3){
      cin >> A.at(i).at(j);
    }
    A.at(i).at(0)--;
    A.at(i).at(1)--;
    edge e1 = {A.at(i).at(1),A.at(i).at(2)};
    edge e2 = {A.at(i).at(0),A.at(i).at(2)};
    vec.at(A.at(i).at(0)).push_back(e1);
    vec.at(A.at(i).at(1)).push_back(e2);
  }
  
  ll Q,K;
  cin >> Q >> K;
  K--;

  queue<ll> que;
  vector<ll> dist(N,-1);
  que.push(K);
  dist[K]=0;
  while(!que.empty()){
    ll v = que.front();
    que.pop();
    for(auto e:vec.at(v)){
      ll nv = e.to;
      ll ncost = e.cost;
      if(dist[nv]!=-1) continue;

      dist[nv]=dist[v]+ncost;
      que.push(nv);
    }
  }

  vector<ll> ans(Q);
  REP(i,Q){
    ll x,y;
    cin >> x >> y;
    x--;
    y--;
    ans.at(i)=dist[x]+dist[y];
  }

  REP(i,Q){
    cout << ans.at(i) << endl;
  }
}