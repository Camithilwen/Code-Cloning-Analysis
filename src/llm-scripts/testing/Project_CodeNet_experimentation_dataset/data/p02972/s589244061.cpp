#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  int n; cin >> n;
  vi a(n); rep(i,n) cin >> a[i];
  vi cnt(n);
  for(int i = n-1; 0 <= i; i--){
    int sum = 0;
    for(int j = i; j < n; j += i+1) sum ^= cnt[j];
    cnt[i] = sum^a[i];
  }
  vi ans;
  rep(i,n) if(cnt[i]) ans.push_back(i+1);
  cout << ans.size() << "\n";
  if(ans.size()) for(auto x : ans) cout << x << " ";
  cout << "\n";
  return 0;
}
