#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int msb(int x) { return 31 - __builtin_clz(x); }

int main() {
  int N; std::cin >> N;
  std::map<int,int> m;
  for(int i = 0; i < N; ++i) { int A; std::cin >> A; ++m[A]; }
  std::vector<std::pair<int,int>> v(m.begin(), m.end());
  int ans = 0;
  for(int j = v.size()-1; j >= 0; --j) {
    if(v[j].second < 1) continue;
    int val = v[j].first;
    int x = (1 << msb(val)+1) - val;
    if(val == x) { ans += v[j].second/2; continue; }
    int i = std::partition_point(v.begin(), v.end(),
              [&](auto const& p) { return p.first < x;}) - v.begin();
    if(i >= j) continue;
    if(v[i].first != x) continue;
    int n = std::min(v[j].second, v[i].second);
    ans += n;
    v[i].second -= n;
  }
  fin(ans);
  return 0;
}
