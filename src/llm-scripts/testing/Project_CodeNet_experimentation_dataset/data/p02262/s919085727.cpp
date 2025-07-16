#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), i##_max = (b); i < i##_max; ++i)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()

using namespace std;

constexpr int INF = 1 << 30;
constexpr int MOD = 1000000007;

static vector<int> G;
static int cnt = 0;

void insert_sort(vector<int> &A, int g) {
  FOR(i, g, A.size()) {
    auto v = A[i];
    auto j = i - g;
    while (j >= 0 && A[j] > v) {
      A[j + g] = A[j];
      j -= g;
      ++cnt;
    }
    A[j + g] = v;
  }
}

void shell_sort(vector<int> &A) {
  for(int h = 1;;) {
    if (h > A.size()) break;
    G.push_back(h);
    h = 3*h + 1;
  }
  reverse(ALL(G));
  REP(i, G.size()) insert_sort(A, G[i]);
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N) cin >> A[i];
  
  shell_sort(A);
  cout << G.size() << endl;
  REP(i, G.size()) {
    if (i) cout << " ";
    cout << G[i];
  }
  cout << endl << cnt << endl;
  for (auto a : A) cout << a << endl;
}

