#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  int n,m;cin>>n>>m;
  vector<int>a(n), b(m);
  rep(i, n)cin>>a[i];
  rep(i, m)cin>>b[i];

  map<int, int>ma, mb;
  for(auto c:a)ma[c]++;
  for(auto p: ma)if(p.second>1) { cout<<0<<endl; return 0; }
  for(auto c:b)mb[c]++;
  for(auto p: mb)if(p.second>1) { cout<<0<<endl; return 0; }

  vector<int> counter_a(n*m+1);
  vector<int> counter_b(n*m+1);
  for(auto c: a)counter_a[c]++;
  for(auto c: b)counter_b[c]++;
  rrep1(i, n*m)counter_a[i-1] += counter_a[i];
  rrep1(i, n*m)counter_b[i-1] += counter_b[i];

  ll result=1;
  rrep1(c, n*m){
    ll cca = counter_a[c];
    ll ccb = counter_b[c];
    ll reduce = (n*m-c);

    if(ma[c]>0 && mb[c]>0);
    else if(ma[c]>0){
      result = result*ccb%MOD;
    }else if(mb[c]>0){
      result = result*cca%MOD;
    }else{
      result = result*(cca*ccb-reduce)%MOD;
    }
  }

  cout<<result<<endl;

  return 0;
}
