#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  
  int ret = 0;
  
  for (int i = A; i <= B; i++) {
    int s1, s2, s4, s5;
    s1 = i / 10000;
    s5 = i % 10;
    
    if (s1 != s5) {
      continue;
    }
    
    s2 = (i / 1000) % 10;
    s4 = (i / 10) % 10;

    if (s2 == s4)
      ret++;
  }
  
  cout << ret << endl;
}
