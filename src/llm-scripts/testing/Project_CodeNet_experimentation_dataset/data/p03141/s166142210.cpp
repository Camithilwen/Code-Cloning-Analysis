#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
int main() {
  int N;
  cin >> N;
  vector<ll> A(N), B(N), C(N);
  rep(i, N) {
    cin >> A[i] >> B[i];
    C[i] = A[i] + B[i];
  }
  sort(all(C), greater<ll>());
  ll sum = 0;
  rep(i, N) if(i%2==0) sum += C[i];
  cout << sum - accumulate(all(B), 0LL) << endl;
  return 0;
}
