#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<vector<int>> ab(N, vector<int>(2));
  for (int i = 0; i < N; i++) {
    cin >> ab.at(i).at(1) >> ab.at(i).at(0);
  }
  vector<vector<int>> cd(N, vector<int>(2));
  for (int i = 0; i < N; i++) {
    cin >> cd.at(i).at(0) >> cd.at(i).at(1);
  }
  sort(ab.begin(), ab.end());
  reverse(ab.begin(), ab.end());
  sort(cd.begin(), cd.end());
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (cd.at(i).at(1) > ab.at(j).at(0) && cd.at(i).at(0) > ab.at(j).at(1)) {
        ans++;
        ab.at(j).at(0) = 200;
        ab.at(j).at(1) = 200; 
        break;
      }
    }
  }
  cout << ans << endl;
}