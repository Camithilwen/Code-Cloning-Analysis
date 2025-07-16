#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}

int main() {
  int N, M; cin >> N >> M;

  vector<queue<int>> A(N, queue<int>());
  rep(i, N) rep(j, M) {
    int a; cin >> a;
    A[i].push(a);
  }

  set<int> used;
  int ans = N;
  rep(i, M) {
    map<int, int> count;
    rep(j, N) {
      while (!A[j].empty() && used.find(A[j].front()) != used.end())
        A[j].pop();
      ++count[A[j].front()];
    }
    int max_count = 0, max_num;
    for (const auto& e : count) {
      int num = e.first, count = e.second;
      if (chmax(max_count, count))
        max_num = num;
    }
    chmin(ans, max_count);
    used.insert(max_num);
  }
  cout << ans << endl;

  return 0;
}
