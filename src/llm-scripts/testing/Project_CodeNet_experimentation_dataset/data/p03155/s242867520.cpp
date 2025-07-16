#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using vst=vector<string>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

map<ll,int> prf(ll n){
  map<ll,int> ret;
  for(ll i=2;i*i<=n;i++){
    while(n%i==0){
     ret[i]++;
      n/=i;
    }
  }
  if(n!=1){
    ret[n]=1;
  }
  return ret;
}


int main(){cout<<fixed<<setprecision(10);
		   int n,h,w;
           cin>>n>>h>>w;
           n++;
           cout<<(n-w)*(n-h)<<endl;
}