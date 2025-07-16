#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll N,M;
  cin >> N >> M;
  if(N*N==M){
    cout << N << endl;
  }else if(N*N<M){
    for(ll i=N;i*i<M;i++){
      if(M%i==0){
        cout << M/i << endl;
        return 0;
      }
    }
    for(ll i=N-1;i>0;i--){
      if(M%i==0){
        cout << i << endl;
        return 0;
      }
    }
  }else{
    for(ll i=M/N;i>0;i--){
      if(M%i==0){
        cout << i << endl;
        return 0;
      }
    }
  }
      
}