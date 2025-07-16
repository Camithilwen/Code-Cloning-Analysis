#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll MAXN = 55556;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  string s;
  cin >> s;
  vector < vector < ll > > v(26, vector < ll > ());
  ll n = s.length();
  for(int i = 0; i < n; i++){
    v[s[i] - 'a'].push_back(i);
  }

  ll ans = (n * (n - 1)) / 2;
  for(int i = 0; i < n; i++){
    ll idx = s[i] - 'a';
    ans -= v[idx].end() - upper_bound(v[idx].begin(), v[idx].end(), i);
  }

  cout << ans + 1 << '\n';
}
