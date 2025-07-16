#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, min_count;
  cin >> n;
  min_count = 200;
  
  for (int i=0; i<n; i++) {
    int a, count = 0;
    cin >> a;
    
    if (a % 2 == 1) {
      min_count = 0;
      break;
    }
    
    while (a % 2 == 0) {
      a /= 2;
      count += 1;
    }
    if (min_count > count)
      min_count = count;
  }
  
  cout << min_count << endl;
}