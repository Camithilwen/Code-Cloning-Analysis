#include <iostream>
#include <vector>
#include <stack>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

#define rep(i,n) for(int i=0;i<(n);++i)

int main() {
  int N, M; cin >> N >> M;

  int in[N];
  vvi edge(N, vi());
  rep(i, N) in[i] = 0;
  rep(i, N-1+M) {
    int a, b; cin >> a >> b;
    --a; --b;
    edge[a].push_back(b);
    ++in[b];
  }
  stack<int> st;
  vi sorted, parent(N, -1);
  rep(i, N)
    if (in[i] == 0) st.push(i);

  while (!st.empty()) {
    int p = st.top(); st.pop();
    sorted.push_back(p);
    for (const auto& e : edge[p]) {
      --in[e];
      if (in[e] == 0) {
        st.push(e);
        parent[e] = p;
      }
    }
  }
  rep(i, N)
    cout << parent[i] + 1 << endl;


  return 0;
}
