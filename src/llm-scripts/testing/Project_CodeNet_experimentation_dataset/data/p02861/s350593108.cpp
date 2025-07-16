#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
using Graph = vector<vector<int>>;

int main() {
  int N;
  cin >> N;
  double X[N];
  double Y[N];
  double sum = 0;
  int num = 0;
  FOR(i,0,N) cin >> X[i] >> Y[i];
  FOR(i,0,N-1) {
    FOR(j,i+1,N) {
      sum += sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]));
      num++;
    }
  }
  double ans = sum/num*(N-1);
  cout << fixed << setprecision(7) << ans << endl;
  return 0;
}