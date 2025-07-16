#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
bool cmp(const pair<ll,ll> &a, const pair<ll,ll> &b){
  if(a.first==b.first)return a.second > b.second;
  else return a.first < b.first;
}
int main()
{
ll n ;
cin >> n ;
vector<pair<ll,ll>> v(n);
ll rmin=0,lmax=0;
rep(i, n){
  cin >> v[i].first >> v[i].second;
  ans=max(ans,v[i].second-v[i].first+1);
  if(v[rmin].second>v[i].second)rmin=i;
  if(v[lmax].first <v[i].first)lmax=i;
}
ans+=max(0LL,v[rmin].second-v[lmax].first+1);
ll ss=v[rmin].second,t=v[lmax].first;
sort(v.begin(),v.end(),cmp);
multiset<ll> s;
rep(i,n)s.insert(v[i].second);
rep(i,n){
  s.erase(s.find(v[i].second));
  ans=max(ans,max(ss-v[i].first+1,0LL)+max(*s.begin()-t+1,0LL));
}
cout << ans << endl;
return 0;
}