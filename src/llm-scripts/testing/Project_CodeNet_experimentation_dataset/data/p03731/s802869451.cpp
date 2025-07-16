#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll N,T;cin >> N >> T;
  ll sum =0;
  vector<ll> C(N);
  for(int i=0;i<N;i++){
    cin >> C[i];
  }
  for(int i=0;i<N-1;i++){
    sum += min(T,C[i+1]-C[i]);
  }
  sum += T;
  cout << sum << endl;
}