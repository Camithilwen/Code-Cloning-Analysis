#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

  
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);  
  
  int n,m;
  cin >> n >> m;
  vector<int>a(n);
  rep(i,n) cin >> a[i];
  vector<int>ans(n);
  rep(i,m){
    int x;
    cin >> x;
    ll kyogi=n;
    rep(j,n){
      if(a[j]<=x){
        kyogi=min(kyogi,j);
      }
    }
    ans[kyogi]++;
  }
  cout << max_element(ans.begin(),ans.end())-ans.begin()+1 << endl;
        
}

