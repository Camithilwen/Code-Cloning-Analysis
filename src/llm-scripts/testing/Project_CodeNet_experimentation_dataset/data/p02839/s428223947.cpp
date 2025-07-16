#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
#define MOD (ll)1000000007
#define PI 3.14159265359
#define debug(x) cout<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
#define P pair<int, int>
#define dvec vector<vector<ll>>
//printf("%.10f\n")
//cout << fixed << setprecision(10);
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}
ll INF = 1e+18;
int iINF = 1e9;


int main()
{
  int H, W; cin >> H >> W;
  vector<vector<pair<int, int>>> grid(H, vector<pair<int, int>>(W, {0, 0}));
  rep(i, 0, H) rep(k, 0, W) cin >> grid[i][k].first;
  rep(i, 0, H) rep(k, 0, W) cin >> grid[i][k].second;
  vector<vector<vector<bool>>> dp(H + 1, vector<vector<bool>>(W + 1, vector<bool>(13000, false)));
  dp[0][1][0] = true;

  
  repe(i, 1, H){
    repe(k, 1, W){
      rep(l, 0, 13000){
        int pre = abs(grid[i - 1][k - 1].first - grid[i - 1][k - 1].second);
        if(dp[i - 1][k][l]){
          dp[i][k][l + pre] = true;
          if(l - pre >= 0) dp[i][k][l - pre] = true;
          if(pre - l >= 0) dp[i][k][pre - l] = true;
        }
        if(k == 1) continue;
        if(dp[i][k - 1][l]){
          dp[i][k][l + pre] = true;
          if(l - pre >= 0) dp[i][k][l - pre] = true;
          if(pre - l >= 0) dp[i][k][pre - l] = true;
        }
      }
    }
  }

  int ans = iINF;
  rep(i, 0, 13000){
    if(dp[H][W][i]){
      ans = i;
      break;
    }
  }
  cout << ans << endl;



}
