#include <iostream>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int N, Q;
  cin >> N >> Q;
  fenwick_tree<long long> t(N);
  for (int i = 0; i < N; ++i) {
    long long a;
    cin >> a;
    t.add(i, a);
  }
  
  for (int i = 0; i < Q; ++i) {
    long long q, arg0, arg1;
    cin >> q >> arg0 >> arg1;
    if (q == 0) {
      t.add(arg0, arg1);
    } else {
      cout << t.sum(arg0, arg1) << endl;
    }
  }
  return 0;
}