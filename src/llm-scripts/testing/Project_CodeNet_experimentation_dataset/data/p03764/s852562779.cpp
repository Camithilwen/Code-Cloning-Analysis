#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; } template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define M 1000000007
#define all(a) (a).begin(),(a).end()
#define rep(i,n) reps(i,0,n)
#define reps(i,m,n) for(int i=(m);i<(n);i++)
int main(){
  ll n,k;cin>>n>>k;
  vector<ll> a(n),b(k);
  rep(i,n)cin>>a[i];
  rep(i,k)cin>>b[i];
  ll c=0LL,d=0LL;
  ll j=-n+1;
  rep(i,n){
    c+=a[i]*j;
    j+=2;
  }
  j=-k+1;
  rep(i,k){
    d+=b[i]*j;
    j+=2;
  }
  cout<<(c%M)*(d%M)%M;
}