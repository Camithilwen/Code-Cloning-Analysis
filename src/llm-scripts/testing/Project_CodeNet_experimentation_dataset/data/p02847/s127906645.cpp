#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  vector<string> V { "SUN","MON","TUE","WED","THU","FRI","SAT" };
  int tmp = 0;
  for (int i = 0; i < V.size(); i++) {
    if (V.at(i) == S) tmp = i;
  }
  cout << 7 - tmp << "\n";
}