#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main()
{
  int N; cin >> N;
  ll ans = 0;
  int k;
  ll r = 0, g = 0, b = 0;
  vector<char> S(N+1);
  FOR(i,1,N+1){
    cin >> S[i];
    if(S[i] == 'R') r++;
    if(S[i] == 'G') g++;
    if(S[i] == 'B') b++;
  }
  ans = r * g * b;
  FOR(i,1,N-1){
    FOR(j,i+1,N){
      k = 2 * j - i;
      if(k > N) break;
      if(S[i] != S[j] && S[i] != S[k] && S[k] != S[j])
        ans--;
    }
  }
  cout << ans << endl;
}