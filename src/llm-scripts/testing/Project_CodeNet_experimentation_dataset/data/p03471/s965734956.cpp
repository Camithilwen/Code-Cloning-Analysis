#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

int main() {
  ll N, Y ; cin >> N >> Y;
  rep(i,N+1){
    rep(j,(N-i+1)){
      if( Y == i*10000 + j*5000 + (N-i-j)*1000 ){
        cout << i << " " << j << " " << N-i-j << endl;
        return 0;
      }
    }
  }
  cout << "-1 -1 -1" << endl;
}