#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,L;
  cin >> N >> L;
  vector<int>A(N);
  vector<int>B(N);
  int sum = 0;
  for (int i = 0; i < N; i++) {
    A.at(i) = L + i;
    sum += A.at(i);
    B.at(i) = abs(A.at(i));
  }
  sort(B.begin(), B.end());

  for (int i = 0; i < N; i++) {
    if (B.at(0) == abs(A.at(i))){
      sum -= A.at(i);
    }
  }
  
  cout << sum << endl;
}

