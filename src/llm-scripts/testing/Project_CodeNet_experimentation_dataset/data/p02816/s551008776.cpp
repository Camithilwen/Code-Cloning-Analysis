#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
vector<ll> z_algorithmll(const vector<ll> &s)
{
  vector<ll> prefix(s.size());
  for (int i = 1, j = 0; i < s.size(); i++)
  {
    if (i + prefix[i - j] < j + prefix[j])
    {
      prefix[i] = prefix[i - j];
    }
    else
    {
      int k = max(0LL, j + prefix[j] - i);
      while (i + k < s.size() && s[k] == s[i + k])
        ++k;
      prefix[i] = k;
      j = i;
    }
  }
  prefix[0] = (int)s.size();
  return prefix;
}
int main()
{
ll n ;
cin >> n ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
}
vector<ll> b(n);
rep(i, n){
  cin >> b[i];
}
vector<vector<ll>> v,vv;
rep(j,30){
  vector<ll> a1;
  vector<ll> a2;
  vector<ll> bb;
  rep(i,n){
    if(a[i]>>j & 1LL){a1.push_back(1);a2.push_back(0);}
    else {a1.push_back(0);a2.push_back(1);}
    if(b[i]>>j & 1LL)bb.push_back(1);
    else bb.push_back(0);
  }
  auto r=bb; r.push_back(-1);
  r.insert(r.end(), a1.begin(), a1.end());
  r.insert(r.end(), a1.begin(), a1.end());
  v.push_back(z_algorithmll(r));
  r=bb; r.push_back(-1);
  r.insert(r.end(), a2.begin(), a2.end());
  r.insert(r.end(), a2.begin(), a2.end());
  vv.push_back(z_algorithmll(r));
}
rep(i,n){
  bool ok=1;
  ll ans=0;
  rep(j,30){
    if(v[j][i+n+1]!=n&&vv[j][i+n+1]!=n){
      ok=0;
      break;
    }
    if(vv[j][i+n+1]==n)ans+=1LL<<j;
  }
  if(ok)cout << i << ' ' << ans <<endl;
}
return 0;
}