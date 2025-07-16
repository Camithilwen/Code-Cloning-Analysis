#include <stdio.h>
#include <vector>
#include <set>
#include <utility>
using namespace std;
typedef long long ll;

int main(void) {
  ll i, j, k, l, n, m, a, b, now, min;
  scanf("%lld%lld", &n, &m);
  vector<ll> vec[n], rev[n];
  ll d[n], be[n];
  pair<ll, ll> p;
  for(i = 0; i < m; ++i) {
    scanf("%lld%lld", &a, &b);
    vec[--a].push_back(--b);
    rev[b].push_back(a);
  }
  for(i = 0; i < n; ++i) {
    set< pair<ll, ll> > s;
    for(j = 0; j < n; ++j) d[j] = 1e9;
    d[i] = 0;
    for(j = 0; j < n; ++j) s.insert(make_pair(d[j], j));
    while(s.size()) {
      p = *s.begin(), s.erase(s.begin());
      if(p.first == 1e9) break;
      for(j = 0; j < vec[p.second].size(); ++j) if(d[vec[p.second][j]] > p.first + 1) {
        s.erase(make_pair(d[vec[p.second][j]], vec[p.second][j]));
        d[vec[p.second][j]] = p.first + 1;
        be[vec[p.second][j]] = p.second;
        s.insert(make_pair(p.first + 1, vec[p.second][j]));
      }
    }
    for(j = 0; j < rev[i].size(); ++j) if(d[rev[i][j]] != 1e9) {
      vector<ll> ans;
      now = rev[i][j];
      while(now != i) ans.push_back(now), now = be[now];
      ans.push_back(i);
      min = ans.size();
      ll flg[n];
      for(k = 0; k < n; ++k) flg[k] = ans.size();
      flg[i] = ans.size() - 1;
      for(now = ans.size() - 2; now >= 0; --now) {
        for(k = 0; k < vec[ans[now]].size(); ++k) if(flg[vec[ans[now]][k]] < min) min = flg[vec[ans[now]][k]];
        if(min != ans.size()) break;
        flg[ans[now]] = now;
      }
      printf("%lld\n", min - now + 1);
      for(k = min; k >= now; --k) printf("%lld\n", ans[k] + 1);
      return 0;
    }
  }
  printf("-1");
  return 0;
}