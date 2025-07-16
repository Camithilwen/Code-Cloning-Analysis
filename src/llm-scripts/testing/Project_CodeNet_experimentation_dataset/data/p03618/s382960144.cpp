#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  string s;
  ll n;
  cin >> s;
  n = s.size();
  vector<ll>cnt(26);
  rep(i,0,n) cnt[s[i]-'a']++;
  ll ans = 1+n*(n-1)/2;
  rep(i,0,26) ans -= cnt[i]*(cnt[i]-1)/2;
  cout << ans << endl;
}