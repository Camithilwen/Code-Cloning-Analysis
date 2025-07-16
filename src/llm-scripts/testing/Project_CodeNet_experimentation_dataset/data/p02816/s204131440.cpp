#include<iostream>
#include<algorithm>
#include<numeric>
#include<map>
#include<set>

int const MAXN = 2e5;
int a[MAXN], b[MAXN], N, k;
int c[MAXN-1], d[MAXN+MAXN-2];
int rank[MAXN+MAXN-1];
int tmp[MAXN+MAXN-1];
int sa[MAXN+MAXN-1];

bool comp_sa(int i, int j) {
  if(rank[i]!=rank[j]) return rank[i] < rank[j];
  int ri = i+k <= N+N-2? rank[i+k]: -1;
  int rj = j+k <= N+N-2? rank[j+k]: -1;
  return ri < rj;
}

int main() {
  std::cin >> N;
  for(int i = 0; i < N; ++i) std::cin >> a[i];
  for(int i = 0; i < N; ++i) std::cin >> b[i];
  for(int i = 0; i < N-1; ++i) c[i] = a[i]^a[i+1];
  for(int i = 0; i < 2*N-2; ++i) d[i] = b[i%N]^b[(i+1)%N];
  std::set<int> ans;
  // SA
  std::copy_n(d, 2*N-2, rank); rank[2*N-2] = -1;
  std::iota(sa, sa+2*N-1, 0);
  for(k = 1; k <= 2*N-2; k += k) {
    std::sort(sa, sa+2*N-1, comp_sa);
    tmp[sa[0]] = 0;
    for(int i = 1; i <= 2*N-2; ++i) {
      tmp[sa[i]] = tmp[sa[i-1]] + (comp_sa(sa[i-1], sa[i])? 1: 0);
    }
    std::copy_n(tmp, 2*N-1, rank);
  }
  int lb = std::partition_point(sa, sa+2*N-1, [&](int i) {
    // d[i, 2*N-2) < c[0, N-1)
    for(int j = 0; j+i < 2*N-2 && j < N-1; ++j) {
      if(d[j+i] != c[j]) return d[j+i] < c[j];
    }
    return 2*N-2-i < N-1;
  }) - sa;
  int ub = std::partition_point(sa, sa+2*N-1, [&](int i) {
    // d[i, 2*N-2) < c[0, N-1) or d[i, i+N-1) == c[0, N-1)
    for(int j = 0; j+i < 2*N-2 && j < N-1; ++j) {
      if(d[j+i] != c[j]) return d[j+i] < c[j];
    }
    return true;
  }) - sa;
  for(int i = lb; i < ub; ++i) {
    ans.insert((N-sa[i])%N);
  }
  // ans
  for(auto k: ans) {
    int x = a[0]^b[(N-k)%N];
    std::cout << k << " " << x << std::endl;
  }
  return 0;
}

