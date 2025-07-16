#include <bits/stdc++.h>
#define INF INT_MAX
#define ll  long long
#define ull unsigned long long
#define rep(i,n) for(ll i=0; i<n; ++i)
#define FOR(i, s, e) for(ll i=s; i<e; ++i)
#define MOD 1000000007
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if(a>b) {a=b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) { if(a<b) {a=b; return true;} return false;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N; cin>>N;
  vector<int> L(N);
  rep(i,N) cin>>L[i];

  int ans = 0;
  for(int i=0; i<N; ++i) {
    for(int j=i+1; j<N; ++j) {
      for(int k=j+1; k<N; ++k) {
        if((L[i] != L[j]) && (L[j] != L[k]) && (L[i] !=L[k])) {
          if((abs(L[i]-L[j]) < L[k]) && (L[k] < (L[i]+L[j]))) {
            ++ans;
          }
        }
      }
    }
  }
  cout << ans << endl;
}