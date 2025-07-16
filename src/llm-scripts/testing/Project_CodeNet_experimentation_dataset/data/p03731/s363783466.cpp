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
  int N,T; cin>>N>>T;
  vi time(N);
  rep(i,N) cin>>time[i];
  ll ans = 0;
  int ct=0;
  rep(i,N){
    if(time[i]>=ct){
      ans += T;
    }
    else {
      ans = ans + time[i] - ct + T;
    }
    ct = time[i]+T;
  }
  cout << ans << endl;
}