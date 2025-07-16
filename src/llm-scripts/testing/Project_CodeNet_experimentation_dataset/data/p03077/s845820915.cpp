#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  ll n;
  cin >> n;
  vector<ll> vec(5);
  rep(i,5) cin >> vec.at(i);
  sort(vec.begin(),vec.end());
  ll ans = 0;
  if (n % vec.at(0) > 0) ans++;
  ans += n / vec.at(0) + 4;
  cout << ans << endl;
}
