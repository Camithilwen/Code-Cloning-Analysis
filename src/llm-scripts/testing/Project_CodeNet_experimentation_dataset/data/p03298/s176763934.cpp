// https://agc026.contest.atcoder.jp/tasks/agc026_c
#include <bits/stdc++.h>
using namespace std;
template<class C>constexpr int sz(const C&c){return int(c.size());}
using ll=long long;constexpr const char nl='\n',sp=' ';

seed_seq seq {
  uint64_t(chrono::duration_cast<chrono::nanoseconds>(
    chrono::steady_clock::now().time_since_epoch()).count()
  ),
  uint64_t(__builtin_ia32_rdtsc()),
  uint64_t(uintptr_t(make_unique<char>().get()))
};

mt19937 rng(seq); mt19937_64 rng64(seq);

const size_t RANDOM = uniform_int_distribution<size_t>(
    0, numeric_limits<size_t>::max())(rng64);
struct rand_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);
  }
  template <class T> size_t operator () (const T &x) const {
    return splitmix64(hash<T>()(x) + RANDOM);
  }
  template <class T1, class T2>
  size_t operator () (const pair<T1, T2> &p) const {
    return 31 * operator ()(p.first) + operator ()(p.second);
  }
};

template <class K, class H = rand_hash, class ...Ts>
using uset = unordered_set<K, H, Ts ...>;
template <class K, class V, class H = rand_hash, class ...Ts>
using umap = unordered_map<K, V, H, Ts ...>;

int N;
string S;
umap<pair<string, string>, ll> M;

int main() {
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  // freopen("err.txt", "w", stderr);
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> N >> S;
  for (int i = 0; i < (1 << N); i++) {
    string red, blue;
    for (int j = 0; j < N; j++) {
      if ((i >> j) & 1) red.push_back(S[j]);
      else blue.push_back(S[j]);
    }
    reverse(blue.begin(), blue.end());
    M[make_pair(red, blue)]++;
  }
  ll cnt = 0;
  for (int i = 0; i < (1 << N); i++) {
    string red, blue;
    for (int j = 0; j < N; j++) {
      if ((i >> j) & 1) red.push_back(S[N + j]);
      else blue.push_back(S[N + j]);
    }
    reverse(blue.begin(), blue.end());
    cnt += M[make_pair(blue, red)];
  }
  cout << cnt << nl;
  return 0;
}
