#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
N=1000ならN*Nで順番付けできそう
違うかな
BFSみたいな

1-2
2-1ならOK

1-2
2-3
3-2
ならOK

みたいな
先頭同士でペアが作れるかどうか

a<bでpair{a,b}を格納して、ペアになったらOKとか
TLEなんだが
N^3になるのか
マッチしたやつだけ再検査すればいいのかな
毎回入れなおしがきつい
*/
int main(){
  ll N; cin>>N;
  ll end=N*(N-1);
  end/=2;
  vector<queue<ll>> Q(N+1);
  queue<pair<ll,ll>> next_Q;
  for(ll i=1; i<=N; i++){
    for(ll j=1; j<N; j++){
      ll a; cin>>a;
      Q[i].emplace(a);
    }
  }
  ll day=1,cnt=0;
  //初期
  for(ll i=1; i<=N; i++){
    ll a=i, b=Q[i].front();
    if(a>b) swap(a,b);
    next_Q.push({a,b});
  }
  set<pair<ll,ll>> S;
  while(!next_Q.empty()){
//cout<<"day:"<<day<<" cnt:"<<cnt<<endl;
    ll Qsz=next_Q.size();
//cout<<"Qsz:"<<Qsz<<endl;    
    for(ll i=0; i<Qsz; i++){
      auto n=next_Q.front();
      ll n1=n.first, n2=n.second;
//cout<<"n1:"<<n1<<" n2:"<<n2<<endl;      
      next_Q.pop();
      auto IT=S.find({n1,n2});
      if(IT!=S.end()){
        Q[n1].pop();
        Q[n2].pop();
        S.erase(IT);
        cnt++;
        ll m1=Q[n1].front();
        if(m1>0){
          if(n1>m1) swap(n1,m1);
          next_Q.push({n1,m1});
        }
        ll m2=Q[n2].front();
        if(m2>0){
          if(n2>m2) swap(n2,m2);
          next_Q.push({n2,m2});
        }
      }
      else S.insert({n1,n2});
    }
    if(cnt==end) break;
    day++;
  }
  if(cnt==end) cout<<day<<endl;
  else cout<<-1<<endl;
}