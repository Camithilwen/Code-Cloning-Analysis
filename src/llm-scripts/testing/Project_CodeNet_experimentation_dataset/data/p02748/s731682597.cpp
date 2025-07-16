#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int A,B,M;cin>>A>>B>>M;
  vector<int>Q(A);for(int i=0; i<A;i++)cin>>Q[i];
  vector<int>W(B);for (int i=0;i<B;i++)cin>>W[i];
  vector<pair<pair<int,int>,int>>C(M);for(int i=0;i<M;i++)cin>>C[i].first.first>>C[i].first.second>>C[i].second;
  int MIN=200000000000;
  auto Q2=Q;auto W2=W;
  sort(Q.begin(),Q.end());sort(W.begin(),W.end());
  MIN=min(MIN,Q[0]+W[0]);
  for(int i=0;i<M;i++){
    MIN=min(MIN,Q2[C[i].first.first-1]+W2[C[i].first.second-1]-C[i].second);
  }
  cout<<MIN<<endl;
}
