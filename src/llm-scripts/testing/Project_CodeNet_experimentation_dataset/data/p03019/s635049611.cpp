#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = INF;

int main()
{
ll n , x ;
cin >> n >> x ;
vector<vector<ll>> v(n, vector<ll>(3,0) );
vector<pair<ll,ll>> s;
ll d=0;
rep(i,n){
  cin >> v[i][0] >> v[i][1] >> v[i][2] ;
  d+=v[i][0]*v[i][1];
  s.emplace_back(v[i][0]*v[i][1]+(x-v[i][0])*v[i][2],i);
}
sort(s.rbegin(),s.rend());
vector<ll> sum;
sum.push_back(s[0].first);
rep(i,n-1)sum.push_back(s[i+1].first+sum.back());
rep(i,n){
  ll z=0,an;
  auto itr = lower_bound(sum.begin(), sum.end(), d);
  z=d-((itr-sum.begin()-1)<0 ? 0 : sum[itr-sum.begin()-1] );
  an=x*(itr-sum.begin());
  if(itr-sum.begin()>i){
    itr = lower_bound(sum.begin(), sum.end(), d+s[i].first);
    z=d-sum[itr-sum.begin()-1]+s[i].first;
    an=x*(itr-sum.begin()-1);
  }
  if(z-v[s[i].second][0]*v[s[i].second][1]>0)an+=v[s[i].second][0]+(z-v[s[i].second][0]*v[s[i].second][1]+v[s[i].second][2]-1)/v[s[i].second][2];
  else an+=(z+v[s[i].second][1]-1)/v[s[i].second][1];
  ans=min(ans,an);
}
cout << ans << endl;
return 0;
}