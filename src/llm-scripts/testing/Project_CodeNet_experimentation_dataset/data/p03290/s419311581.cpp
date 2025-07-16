#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int main(){
  int d,g;cin >> d >> g;
  vector<int> p(10),c(10);
  rep(i,d) cin >> p[i] >> c[i];
  int ind = 0;
  int sum = 0;
  int ans = INF;
  int cnt = 0;
  rep(i,1<<d){
    sum = 0;
    cnt = 0;
    rep(j,d){
      if(i>>j&1) {
        sum += p[j]*(j+1)*100;
        sum += c[j];
        cnt += p[j];
      }else ind = j;
    }
    if(g-sum > (p[ind]-1)*(ind+1)*100) continue;
    cnt += max(g-sum + (ind+1)*100 -1,0)/((ind+1)*100);
    ans = min(ans,cnt);
  }

  cout << ans << endl;
}