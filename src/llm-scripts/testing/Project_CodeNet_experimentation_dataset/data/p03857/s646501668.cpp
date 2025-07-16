#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int, int> P;

class UnionFind {
  public:
    vector<int> Parent;

    UnionFind(int N) {
      Parent = vector<int>(N, -1);
    }

    int root(int A) {
      if(Parent[A] < 0) return A;
      return Parent[A] = root(Parent[A]);
    }

    int size(int A) {
      return -Parent[root(A)];
    }

    bool connect(int A, int B) {
      A = root(A);
      B = root(B);
      if(A==B) {
        return false;
      }

      if(size(A) < size(B)) swap(A, B);
      Parent[A] += Parent[B];
      Parent[B] = A;
      return true;
    }
};

int main() {
  int N, K, L; cin >> N >> K >> L;
  UnionFind Uni(N);
  UnionFind U(N);
  map<P, int> m;
  for(int i = 0; i < K; ++i) {
    int p, q; cin >> p >> q;
    p--, q--;
    Uni.connect(p, q);
  }
  for(int i = 0; i < L; ++i) {
    int r, s; cin >> r >> s;
    r--, s--;
    U.connect(r, s);
  }
  for(int i = 0; i < N; ++i) {
    try {
      int cnt = m.at({Uni.root(i), U.root(i)});
      m.erase({Uni.root(i), U.root(i)});
      m.insert({{Uni.root(i), U.root(i)}, cnt+1});
    } catch(std::out_of_range&) {
      m.insert({{Uni.root(i), U.root(i)}, 1});
    }
  }
  for(int i = 0; i < N; ++i) {
    try {
      cout << m.at({Uni.root(i), U.root(i)});
    } catch(std::out_of_range&) {
      cout << 0;
    }
    if(i != N-1) cout << " ";
  }
  cout << endl;
  return 0;
}
