#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;

int main(){
  ll N,M;
  cin >> N >> M;
  if(M%2==0){
    rep(i,M/2){
      cout << i+1 << " " << M-i+1 << endl;
      cout << M+i+2 << " " << 2*M-i+1 << endl;
    }
  }else{
    rep(i,M/2){
      cout << i+1 << " " << M-i+1 << endl;
      cout << M+i+2 << " " << 2*M-i+1 << endl;
    }
    cout << M/2+1 << " " << M/2+2 << endl;
  }
}