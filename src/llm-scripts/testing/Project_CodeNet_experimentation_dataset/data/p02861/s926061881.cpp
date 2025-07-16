#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
typedef long long ll;
using namespace std;

int main() {
  int n;
  double avg = 0, count = 0;
  cin >> n;
  std::vector<int> v(n), x(n), y(n);
  REP(i,n){
    v.at(i) = i;
    cin >> x.at(i) >> y.at(i);
  }

  do {
    REP(i,n-1){
      avg += sqrt(pow(x[v[i]]-x[v[i+1]],2) + pow(y[v[i]]-y[v[i+1]],2));
    }
    count += 1;
  } while (std::next_permutation(v.begin(), v.end()));
  cout << fixed << setprecision(10) << avg / count;

  return 0;

}

