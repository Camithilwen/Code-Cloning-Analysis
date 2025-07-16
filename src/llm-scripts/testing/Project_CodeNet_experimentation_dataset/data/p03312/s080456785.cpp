#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int64_t const INF = 1e18;

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N; std::cin >> N;
  std::vector<int64_t> A(N), S(N+1, 0);
  for(int i = 0; i < N; ++i) std::cin >> A[i];
  for(int i = 0; i < N; ++i) S[i+1] = S[i] + A[i];
  auto split = [&](auto b, auto e)-> std::pair<int64_t,int64_t> {
    int64_t V = (*e + *b)/2;
    auto m = std::upper_bound(b, e, V);
    int64_t mi = INF;
    std::pair<int64_t, int64_t> res;
    for(auto i: {m-1, m, m+1}) if(b < i && i < e) {
      int64_t cur = std::abs((*i-*b) - (*e-*i));
      if(cur < mi) { mi = cur; res = std::make_pair(*i-*b, *e-*i); }
    }
    return res;
  };
  auto isOK = [&](int64_t k)->bool {
    int64_t vmi = (S[N]+1)/2 - k, vma = S[N]/2 + k;
    auto lb = std::lower_bound(S.begin()+2, S.end()-3, vmi);
    auto ub = std::upper_bound(S.begin()+2, S.end()-2, vma);
    for(auto it = lb; it != ub; ++it) {
      auto L = split(S.begin(), it);
      if(std::abs(L.first - L.second) > k) continue;
      auto R = split(it, S.end()-1);
      if(std::abs(R.first - R.second) > k) continue;
      if(std::abs(L.first - R.first) > k) continue;
      if(std::abs(L.first - R.second) > k) continue;
      if(std::abs(L.second - R.first) > k) continue;
      if(std::abs(L.second - R.second) > k) continue;
      return true;
    }
    return false;
  };
  
  int64_t ng = -1, tmp[6];
  tmp[0] = std::abs(S[N] - S[3] - A[0]);
  tmp[1] = std::abs(S[N] - S[3] - A[1]);
  tmp[2] = std::abs(S[N] - S[3] - A[2]);
  tmp[3] = std::abs(A[0] - A[1]);
  tmp[4] = std::abs(A[0] - A[2]);
  tmp[5] = std::abs(A[1] - A[2]);
  int64_t ok = *std::max_element(tmp, tmp+6);
  while(ok - ng > 1) {
    int64_t mid = (ok+ng)/2;
    if(isOK(mid)) ok = mid; else ng = mid;
  }
  fin(ok);
  return 0;
}
