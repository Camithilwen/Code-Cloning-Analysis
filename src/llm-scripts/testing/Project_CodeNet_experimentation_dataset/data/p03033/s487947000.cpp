#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
struct edge { ll s, t, x; };
typedef pair<ll, ll> P;
typedef pair<double, P> event;
const ll MAX = 510000;
const ll MOD = 1000000007;
#define INF (ll)10000000000000000

int main() {
  ll N,Q;
  cin>>N>>Q;
  priority_queue<event>pq;
  set<ll>st;
  //eventはP(P(a,b),c)で書き、
  //aに時刻をもち,b=0→工事開始,1→終了,2→歩行者とする
  rep(i,N){
    double s,t;
    ll x;
    cin>>s>>t>>x;
    s=(double)x-s+0.5;
    t=(double)x-t+0.5;
    pq.push(event(s,P(0ll,x)));
    pq.push(event(t,P(1ll,x)));
  }
  rep(i,Q){
    double g;
    cin>>g;
    pq.push(event(-1*g,P(2ll,0ll)));
  }
  while(!pq.empty()){
    auto t=pq.top();
    pq.pop();
    if(t.second.first==0){
      st.insert(t.second.second);
    }
    if(t.second.first==1){
      st.erase(t.second.second);
    }
    if(t.second.first==2){
      if(st.empty()){cout<<-1<<endl;}
      else{
        cout<<*begin(st)<<endl;
      }
    }
  }
}