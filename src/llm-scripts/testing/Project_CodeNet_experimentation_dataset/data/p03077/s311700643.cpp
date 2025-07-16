#include <bits/stdc++.h>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const ll Lmax=ll(1e18);
const ll Nmax=1e9;
const ll INF=1e9;


int main(){
  ll n,a,b,c,d,e;
  cin>>n>>a>>b>>c>>d>>e;
  ll m=min(a,min(b,min(c,min(d,e))));

  cout<<(n-1)/m+5;
}
