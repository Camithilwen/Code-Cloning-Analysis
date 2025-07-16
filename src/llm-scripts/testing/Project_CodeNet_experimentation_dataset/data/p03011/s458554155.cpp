#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  vector<int> time(3);
  vector<int> subsc = {0, 1, 2};
  rep(i, 3) cin >> time[i];
  int cmp = 100000000;
  do {
    int sum = 0;
    rep(i, 2) sum += time[subsc[i]];
    cmp = min(sum, cmp);
  }while(next_permutation(subsc.begin(), subsc.end()));
  
  cout << cmp << endl;
  return 0;
}
    