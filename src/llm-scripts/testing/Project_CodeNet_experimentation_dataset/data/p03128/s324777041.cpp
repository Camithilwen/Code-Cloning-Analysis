#include<iostream>
#include<iomanip>
#include<algorithm>
#include<bitset>
#include<cstdio>
#include<cmath>
#include<deque>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<tuple>
#include<utility>
#include<vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<vector<int>> vvi;

#define rep(i, a, n)  for(int i=a; i<n; i++)
#define REP(i, n)  for(int i=0; i<(int)(n); i++)
#define REPS(i, n)  for(int i=1; i<=(int)(n); i++)
#define PER(i, n) for(int i=(int)(n)-1; i>= 0; i--)
#define PERS(i, n)  for(int i=(int)(n); i>0; i--)
#define FOR(i, c) for(__typeof((c).begin()) i = (c).begin(); i!=(c).end(); i++)
#define RFOR(i, c)  for(__typeof((c).rbegin()) i=(c).rbegin(); i!=(c).end(); i++)
#define ALL(container)  (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) (container).size()
#define FILL0(n)  setfill('0') << right << setw(n)
#define mp(a, b)  make_pair(a, b)
#define toLower(c)  c+0x20
#define toUpper(c)  c-0x20
#define pb  push_back
#define eb  emplace_back

const int INF = 1e9;
const long long LLINF = 1e18;
const ull MOD = 998244353;
const int MSIZE = 100007;
const double Pi = 3.14159265358979323146;

int main(){
  int match[10] = {6,2,5,5,4,5,6,3,7,6};
  int n, m; cin >> n >> m;
  vector<int> num(m), dp(n+100, -INF);
  REP(i, m){
    cin >> num[i];
  }
  dp[0]=0;
  sort(RALL(num));
  string ans = "";
  for(int i=1; i<=n; i++){
    REP(j, m){
      if(i-match[num[j]]<0) continue;
      dp[i] = max(dp[i], dp[i-match[num[j]]]+1);
    }
  }
  //cout << n << ":" << ans << endl;

  while(n>0){
    REP(j, m){
      if(n-match[num[j]]<0) continue;
      if(dp[n-match[num[j]]]==dp[n]-1){
        ans += ('0'+num[j]);
        n-=match[num[j]];
        //cout << n << ":" << ans << endl;
        break;
      }
    }
  }
  cout << ans << endl;
}
