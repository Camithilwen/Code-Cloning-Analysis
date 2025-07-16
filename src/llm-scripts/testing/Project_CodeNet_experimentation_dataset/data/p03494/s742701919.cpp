#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> A(N), B(N);
  
  for (int i = 0; i < N; i++) cin >> A.at(i);
  
  int min_count = 0;
  
  int x0 = A.at(0);
  while (x0 % 2 == 0) {
    min_count++;
    x0 = x0 / 2;
  }
  
  for (int x : A) {
      int count = 0;
      while (x % 2 == 0) {
        count++;
        x = x / 2;
      }
    min_count = min (min_count, count);
  }
  
  cout << min_count << endl;
}
