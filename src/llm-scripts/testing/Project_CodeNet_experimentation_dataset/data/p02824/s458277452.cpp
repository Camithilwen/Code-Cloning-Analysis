#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

bool fc(vector<int> &a, int m, int v, int p, int mid){
  int n = a.size();
  if(mid < p) return true;
  vector<int> tr;
  rep(i, n){
    if(i == mid) continue;
    tr.push_back(a.at(i));
  }

  ll top = a.at(mid) + m;
  if(top < tr.at(p-1)) return false;
  ll ex = (ll)(v-1)*m;
  rep(i, n-1){
    if(i < p-1) ex -= m;
    else ex -= min((ll)m, top - tr.at(i));
  }
  return ex <= 0;
}

int main(){
  int n, m;
  cin >> n >> m;
  int v, p;
  cin >> v >> p;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  sort(ALL(a), greater<int>());
  int ng = n, ok = 0;
  while(ng - ok > 1){
    int mid = (ok + ng)/2;
    if(fc(a, m, v, p, mid) == true) ok = mid;
    else ng = mid;
  }
  int ans = ok+1;
  cout << ans << endl;
  return 0;
}