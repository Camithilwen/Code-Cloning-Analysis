#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,K;
  cin >> N >> K;
  
  vector<int>x(N);
  for (int i = 0; i < N; i++) {
    cin >> x.at(i);
  }

  vector<int>A(N-K+1);
  for (int i = K-1; i < N; i++) {
    A.at(i-K+1) = x.at(i) - x.at(i-K+1);
    A.at(i-K+1) += min(abs(x.at(i)),abs(x.at(i-K+1)));
  }
  sort(A.begin(), A.end());
  cout << A.at(0) << endl;
}
 