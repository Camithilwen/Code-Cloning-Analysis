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
      auto R = split(it, S.end()-1);
      int64_t P[4] = {L.first, L.second, R.first, R.second};
      if(*std::max_element(P, P+4) - *std::min_element(P, P+4) <= k) return true;
    }
    return false;
  };
  
  int64_t ng = -1;
  // rough try
  auto split2 = [&](auto b, auto e) {
    int64_t V = (*e + *b)/2;
    auto m = std::upper_bound(b, e, V);
    int64_t mi = INF;
    auto res = e+1;
    for(auto i: {m-1, m, m+1}) if(b < i && i < e) {
      int64_t cur = std::abs((*i-*b) - (*e-*i));
      if(cur < mi) { mi = cur; res = i; }
    }
    return res;
  };
  auto M = split2(S.begin(), S.end()-1);
  while((M-S.begin()) < 2) ++M;
  while((M-S.begin()) > S.size()-3) --M;
  auto L = split(S.begin(), M);
  auto R = split(M, S.end()-1);
  int64_t P[4] = {L.first, L.second, R.first, R.second};
  int64_t ok = *std::max_element(P, P+4) - *std::min_element(P, P+4);
  while(ok - ng > 1) {
    int64_t mid = (ok+ng)/2;
    if(isOK(mid)) ok = mid; else ng = mid;
  }
  fin(ok);
  return 0;
}

