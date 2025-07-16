#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define P pair<int,int>
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

const int MAXN = 1010;
const int MAXV = MAXN*(MAXN-1)/2;

vint to[MAXV];
int id[MAXN][MAXN];

bool visited[MAXV];
int dp[MAXV];
bool calculated[MAXV];

int dfs(int a){
  if(visited[a]){
    if(!calculated[a]){
      return -1;
    }
    return dp[a];
  }
  visited[a] = true;
  dp[a] = 1;
  for(int p:to[a]){
    int u = dfs(p);
    if(u == -1){
      return -1;
    }
    dp[a] = max(dp[a],u+1);
  }
  calculated[a] = true;
  return dp[a];
}

int toID(int a,int b){
  if(a < b) swap(a,b);
  return id[a][b];
}

signed main(){
  int n;
  cin >> n;
  vvint A(n,vint(n-1));
  rep(i,0,n){
    rep(j,0,n-1){
      cin >> A[i][j];
      A[i][j]--;
    }
  }
  int v = 0;
  rep(i,0,n){
    rep(j,0,n){
      if(i > j){
        id[i][j] = v;
        v++;
      }
    }
  }
  rep(i,0,n){
    rep(j,0,n-1){
      A[i][j] = toID(i,A[i][j]);
    }
  }
  rep(i,0,n){
    rep(j,0,n-2){
      to[A[i][j+1]].push_back(A[i][j]);
    }
  }
  int ans = 0;
  rep(i,0,v){
    int res = dfs(i);
    if(res == -1){
      cout << -1 << endl;
      return 0;
    }
    ans = max(ans,res);
  }
  cout << ans << endl;
}
