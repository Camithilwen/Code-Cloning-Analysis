#include <iostream>
#include <vector>
#include <bitset>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;
 
int main(){
  ll N;
  cin >> N;

  vector<ll> a(N);
  for(ll i=0;i<N;i++) cin >> a[i];

  vector<ll> si(N);
  ll sum=0;
  for(ll i=0;i<N;i++){
    sum+=a[i];
    si[i]=sum;
  }

  ll p,q,r,s;
  ll n,m;
  ll ans=sum;

    
  for(ll i=1;i<N-2;i++){
    n=0;
    m=i;
    while(n+1<m){
      if(si[(n+m)/2]*2<si[i]){
	n=(n+m)/2;
      }else{
	m=(n+m)/2;
      }
    }
    if(abs(2*si[m]-si[i])<abs(2*si[n]-si[i])) n=m;
    p=si[n];q=si[i]-si[n];

    n=i+1;
    m=N-2;
    while(n+1<m){
      if((si[(n+m)/2]-si[i])*2<si[N-1]-si[i]){
	n=(n+m)/2;
      }else{
	m=(n+m)/2;
      }
    }
    if(abs(si[N-1]-2*si[m]+si[i])<abs(si[N-1]-2*si[n]+si[i])) n=m;
    r=si[n]-si[i];s=si[N-1]-si[n];

    ans=min(ans, max({p,q,r,s})-min({p,q,r,s}));
  }

  cout << ans << endl;
  
  return 0;
}
