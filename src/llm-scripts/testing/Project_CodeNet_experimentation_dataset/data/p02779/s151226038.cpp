#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N;
  cin >> N;
  
  vector<int> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  
  sort(A.begin(), A.end());
  for(int i = 0; i < N; i++) {
//    cout << A.at(i) << endl;
  }
  
  for(int i = 0; i < N-1; i++) {
    if(A.at(i) == A.at(i+1)) {
      cout << "NO" << endl;
      break;
    }
    else if(i == N-2) cout << "YES" << endl;
  }
  
}