#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
using P = pair<int,int>;
using ivec = vector<int>;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }


const int MOD=1000000007;
int INF=100100100100100;

int a[100010];
signed main(){
  int n;cin>>n;
  ivec dp(n+1,INF);
  rep(i,n)cin>>a[n-1-i];
  rep(i,n){
    *lower_bound(all(dp),a[i]+1)=a[i];
  }
  cout<<lower_bound(all(dp),INF)-dp.begin()<<endl;
  return 0;
}
