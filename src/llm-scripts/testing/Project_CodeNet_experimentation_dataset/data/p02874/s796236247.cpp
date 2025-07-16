//#define _GLIBCXX_DEBUG
#include <iostream>
#include <bits/stdc++.h>
    
    
using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cout(n) cout<<fixed<<setprecision(n)

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  cin>>n;
  ll l_max=0,r_min=1e10;
  vector<vector<ll>> v(n);
  ll res = 0;
  FOR(i,0,n){
    ll in,in1;
    cin>>in>>in1;
    in1++;
    v[i].push_back(0);
    v[i].push_back(in);
    v[i].push_back(in1);
    l_max = max(l_max,in);
    r_min = min(r_min,in1);
    res = max(res, in1-in);//max_width
  }
  res = res + max(r_min - l_max, (ll) 0);

  FOR(i,0,n) v[i][0] = max((ll)0, v[i][2]-l_max);
  sortAl(v);
  ll r=1e10,l=0;
  vector<ll> a(n),b(n);
  FOR(i,0,n){
    r = min(r,v[i][2]);
    l = max(l,v[i][1]);
    a[i] = max(r-l,(ll)0);
  }
  r = 1e10;
  l = 0;
  FORr(i,0,n-1){
    r = min(r,v[i][2]);
    l = max(l,v[i][1]);
    b[i] = max(r-l,(ll)0);
  }

  ll ans=0;
  FOR(i,0,n-1) ans = max(ans, a[i] + b[i+1]);
  cout<<max(ans,res)<<endl;
  


}