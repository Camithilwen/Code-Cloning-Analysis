#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define F first
#define S second

#define f(i,a,b)  for(int i = a; i < b; i++)
// #define endl '\n'

using ll = long long;
using db = long double;
using ii = pair<int, int>;

const int N = 55, LG = 17, MOD = 1e9+7;
const int SQ = 320;
const long double EPS = 1e-7;
int cnt = 0;
vector<string> store[11];
void bt(string s = "", int sum = 0){
  if(sum > 7)return;
  store[sum].pb(s);
  f(i,0,7){
    s.pb('0' + i);
    bt(s,sum+i+1);
    s.pop_back();
  }
}
const int M = 10;
int trie[N*N*N][M];
int go[N*N*N][M];
int mrk[N*N*N], f[N*N*N];
int ptr = 1;
void BFS(){

  queue<int> q;
	for(int i = 0; i < M; i++)
		if(trie[0][i])
			q.push(trie[0][i]), f[trie[0][i]] = 0;
	for(int i = 0; i < M; i++) go[0][i] = trie[0][i];
	while(!q.empty()) {
		int x = q.front(); q.pop();
		for(int i = 0; i < M; i++) {
			if(trie[x][i]) {
				int y = trie[x][i];
				f[y] = f[x];
				while(f[y] && !trie[f[y]][i])
					f[y] = f[f[y]];
				if(trie[f[y]][i]) f[y] = trie[f[y]][i];
				q.push(y);
			}
			if(trie[x][i]) go[x][i] = trie[x][i];
			else go[x][i] = go[f[x]][i];
		}
	}

}
void ins(string x){
  int cur = 0;
  for(int i = 0; i < x.size(); i++){
      if(!trie[cur][x[i]-'0'])
        trie[cur][x[i]-'0'] = ptr++;
      cur = trie[cur][x[i]-'0'];
  }
  mrk[cur] = true;
}
int dp[N][N*N*N][2];
int n, x, y, z;
int solve(int idx, int state, bool f){
  f|=mrk[state];
  if(idx == n)
    return f;
  int &ret = dp[idx][state][f];
  if(~ret)
    return ret;
  ret = 0;
  f(j,0,10){
    ret += solve(idx+1,go[state][j], f);
    if(ret>=MOD)ret-=MOD;
  }
  return ret;
}
int32_t main(){
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE



  bt();

  cin >> n >> x >> y >> z;

  for(auto X : store[x])
    for(auto Y : store[y])
      for(auto Z : store[z])if(X.size()+Y.size()+Z.size()<=n)
        ins(X+Y+Z);
  BFS();
  memset(dp,-1,sizeof dp);
  cout << solve(0,0,0) << '\n';

  return 0;
}
