#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vec = vector<ll>;
using vecp = vector<P>;
using mat = vector<vec>;
using matp = vector<vecp>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define all(v) v.begin(), v.end()

void no_cost_graphmake(ll E,mat &G){
  rep(i,E){
    ll a,b;
    cin >> a >> b;
    G.at(a-1).push_back(b-1);
    G.at(b-1).push_back(a-1);//有向なら消す
  }
}
ll W=0,B=0;
bool nibugraph(mat &G,ll n){
  vec A(n,0);
  rep(j,n){
    if(A.at(j)==0){
      A.at(j)=1;
      W++;
      queue<ll> Q;
      Q.push(j);
      while(!Q.empty()){
        ll a=Q.front();
        Q.pop();
        rep(i,(ll)G.at(a).size()){
          if(A.at(G.at(a).at(i))==0){
            A.at(G.at(a).at(i))=3-A.at(a);
            if(A.at(G.at(a).at(i))==1){
              W++;
            }else{
              B++;
            }
            Q.push(G.at(a).at(i));
          }else if(A.at(G.at(a).at(i))==A.at(a)){
            return false;
          }
        }
      }
    }
  }
  return true;
}

int main(){
  ll N,M;
  cin >> N >> M;
  mat G(N);
  no_cost_graphmake(M,G);
  if(nibugraph(G,N)){
    cout << W*B-M << endl;
  }else{
    cout << (N*(N-1))/2-M << endl;
  }
}
