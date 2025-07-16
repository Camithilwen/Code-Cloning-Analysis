#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  long long r = 0, g = 0, b = 0;
  for(int i = 0; i < n; i++) {
    if(s.at(i) == 'R') r++;
    else if(s.at(i) == 'G') g++;
    else b++;
  }
  long long sum = r * g * b;
  for(int i = 0; i < (n - 2); i++) {
    for(int j = i + 1; j < (n - 1); j++) {
      if(s.at(i) != s.at(j)) {
        if(j + (j - i) >= n) {
          continue;
        }
        char x = s.at(j + (j - i));
        if(s.at(i) != x && s.at(j) != x) sum--;
      }
    }
  }
  cout << sum << endl;
}