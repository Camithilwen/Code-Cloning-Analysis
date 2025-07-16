#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int N, Q; cin >> N >> Q;
  fenwick_tree<long long> fw(N);
  rep(i, N) {
    int a; cin >> a;
    fw.add(i, a);
  }
  rep(query, Q) {
    int a, b, c; cin >> a >> b >> c;
    if (a == 0) fw.add(b, c);
    else cout << fw.sum(b, c) << endl;
  }
}