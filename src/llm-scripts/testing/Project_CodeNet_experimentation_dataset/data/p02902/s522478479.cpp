#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

uint64_t getZ() {
  uint64_t v = 0; int c;
  while((c = getchar_unlocked()) >= '0') v=v*10+c-'0';
  return v;
}

template<int BUFSIZE>
struct ans_buf {
  char buf[BUFSIZE];
  int i;
  ans_buf(): i(0) {}
  void putZ(uint64_t v, char delim='\n') {
    uint64_t k = 1;
    while(k <= v/10) k*=10;
    for(; k>0; v%=k, k/=10) buf[i++] = (v/k)+'0';
    buf[i++] = delim;
  }
  void out() { std::fwrite(buf, 1, i, stdout); }
};

int const MAXN = 1000;
int N, M;
std::vector<int> G[MAXN];
bool used[MAXN];

int nv[MAXN], n;
bool dfs(int v) {
  used[v] = true;
  for(auto c: G[v]) {
    nv[v] = c;
    if(c == n) return true;
    if(!used[c] && dfs(c)) return true;
  }
  return false;
}

int main() {
  N = getZ(); M = getZ();
  for(int i = 0; i < M; ++i) G[getZ()-1].push_back(getZ()-1);
  for(int i = 0; i < N; ++i) {
    std::fill_n(used, N, false);
    if(dfs(n = i)) break;
    n = -1;
  }
  if(n < 0) fin(n);
  for(;;) {
    std::fill_n(used, N, false);
    used[n] = true;
    for(int k = nv[n]; k!=n; k=nv[k]) used[k] = true;
    bool ok = true;
    for(int i = 0; i < N; ++i) if(used[i]) {
      for(auto c: G[i]) if(used[c] && c != nv[i]) {
        nv[i] = n = c;
        ok = false;
        break;
      }
      if(!ok) break;
    }
    if(ok) break;
  }
  int ans = 0;
  for(int i = 0; i < N; ++i) if(used[i]) ++ans;
  ans_buf<4000> buf;
  buf.putZ(ans); 
  for(int i = 0; i < N; ++i) if(used[i]) buf.putZ(i+1);
  buf.out();
  return 0;
}
