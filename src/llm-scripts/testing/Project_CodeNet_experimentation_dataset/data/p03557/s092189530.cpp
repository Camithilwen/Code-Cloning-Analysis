#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  int n;
  cin>>n;
  vin a(n),b(n),c(n);
  rep(i,0,n)cin>>a[i];rep(i,0,n)cin>>b[i];rep(i,0,n)cin>>c[i];
  sort(all(a));sort(all(b));sort(all(c));reverse(all(c));
  ll ans=0;
  rep(i,0,n){
    int m=b[i];
    //二分探索
    ll acnt=0;
    int ok=-1,ng=n;
    while(ng-ok>1){
      int mid=ok+(ng-ok)/2;
      if(a[mid]<m)ok=mid;
      else ng=mid;
    }
    acnt=ok+1;
    ll ccnt=0;
    ok=-1,ng=n;
  //  cout<<m<<endl;
    while(ng-ok>1){
     // if(m==2)cout<<ok<<" "<<ng<<endl;
      int mid=ok+(ng-ok)/2;
      if(c[mid]>m)ok=mid;
      else ng=mid;
      
    }
    ccnt=ok+1;
   // cout<<acnt<<" "<<ccnt<<endl;
    ans+=acnt*ccnt;
  }
  cout<<ans<<endl;
}