#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
typedef pair<int,int> P;
const int MOD = 1000000007;
const ll INF = 1e10;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 




////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////

int n,m,a[310][310], ans;
int cnt[310];bool used[310];
void j(){
  P mx;
  while(true){
    rep(i,m)cnt[i] = 0;
    rep(i,n){
      rep(j,m){
        if(!used[a[i][j]]){
          cnt[a[i][j]]++;
          break;
        }
      }
    }
    mx = P(-1, -1);
    rep(i,m)if(mx.first < cnt[i])mx = P(cnt[i], i);
    chmin(ans, mx.first);
    used[mx.second] = true;
    bool r = false;rep(i,m)if(!used[i])r = true;
    if(!r)return;
  }
}

signed main(){
  cin>>n>>m;
  rep(i,n)rep(j,m){
    cin>>a[i][j];a[i][j]--;
  }
  ans = INF;j();
  cout << ans << endl;
}
