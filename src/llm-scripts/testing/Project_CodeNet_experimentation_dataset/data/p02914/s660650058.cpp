#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcountll

#define INF 1e16
#define mod 1000000007

void gauss(vector<ll>& a){
  ll n=a.size();
  ll rank=0;
  for(ll b=(1LL<<60LL);b>=1;b>>=1){
    ll p=rank;
    while(p<n&&!(a[p]&b))p++;
    if(p==n)continue;
    swap(a[rank],a[p]);
    rep(i,n){
      if(i==rank)continue;
      if(a[i]&b)a[i]^=a[rank];
    }
    rank++;
  }
  a.resize(rank);
  sort(all(a));
  reverse(all(a));
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  vector<ll> a;
  cin>>n;
  ll sum=0;
  a.resize(n);
  rep(i,n){
    cin>>a[i];
    sum^=a[i];
  }

  rep(i,n){
    rep(j,60){
      if((sum>>j)&1LL){
        if((a[i]>>j)&1LL){
          a[i]^=(1LL<<j);
        }
      }
    }
  }

  sort(all(a)); 
  gauss(a);

  ll mx=0;
  rep(i,a.size()){
    if(mx<(mx^a[i])){
      mx^=a[i];
    }
  }
  cout<<mx*2+sum<<endl;

  return 0;
}
