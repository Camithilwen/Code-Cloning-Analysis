#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fs first
#define sc second
using namespace std;
typedef long long ll;
int N;
map<ll, int> h;
vector<ll> v;
string s;
pair<ll, ll> frac[200100];
ll cnt[110][110];

pair<ll, ll> getFrac(string &s) {
  ll x = 0, y = 1;
  bool dec = false;
  for(int i=0;i<s.size();++i) {
    if(s[i] == '.') {
      dec = true;
      continue;
    }
    x = x*10 + (s[i] - '0');
    if(dec) y = y*10;
  }
  ll d = __gcd(x, y);
  x /= d; y /= d;
  if(!h[y]) {
    h[y] = 1;
    v.pb(y);
  }
  return mp(x, y);
}

int main() {
  cin>>N;
  ll ret = 0;
  for(int i=0;i<N;++i) {
    cin>>s;
    frac[i] = getFrac(s);
  }
  sort(v.begin(), v.end());
  for(int i=0;i<v.size();++i) h[v[i]] = i;
  for(int i=0;i<N;++i) {
    ll a = frac[i].fs, b = frac[i].sc;
    for(int j=0;j<v.size();++j) {
      if(a % v[j] == 0) {
        ret += cnt[h[b]][j];
      }
    }
    for(int j=0;j<v.size();++j) {
      if(a % v[j] == 0) {
        ++cnt[j][h[b]];
      }
    }
  }
  cout<<ret<<"\n";
}