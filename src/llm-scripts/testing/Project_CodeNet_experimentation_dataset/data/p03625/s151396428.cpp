#include <bits/stdc++.h>
using namespace std;

int main() {
  long N;
  cin >> N;
  vector<long> A(N);
  for (long i = 0; i < N; i++) cin >> A.at(i);
  sort(A.rbegin(), A.rend());
  
  long a = 0, b = 0;
  for (long i = 0; i + 1 < N; i++) {
    if (A.at(i) == A.at(i + 1)) {
      if (!a) a = A.at(i++);
     
      else b = A.at(i++);
        
      if (b) break;
    }
  }
  cout << a * b << "\n";
}
