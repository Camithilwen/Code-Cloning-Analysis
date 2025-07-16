#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,l,r) for(i=l;i<r;i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define P pair<ll,ll>
#define F first
#define S second
signed main(){
  ll n,m,d;cin>>n>>m>>d;if(d)d=2*(n-d);else d=n;
  printf("%.20f",(double)(m-1)*d/(double)(n*n));cout<<endl;
  return 0;
}