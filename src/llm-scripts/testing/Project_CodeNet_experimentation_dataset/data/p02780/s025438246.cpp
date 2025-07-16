#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,K;
  cin >> N >> K;
  vector<int>p(N);
  for (int i = 0; i < N; i++) {
    cin >> p.at(i);
  }
  vector<int>sum1(N,0);
  for (int i = 0; i < N; i++) {
    if (i == 0){
      sum1.at(i) = p.at(i);
    }
    else {
      sum1.at(i) = sum1.at(i-1) + p.at(i);
    }
  }
  
  vector<int>sum2(N-K+1);
  for (int i = 0; i < N-K+1; i++) {
    sum2.at(i) = sum1.at(K-1+i) - sum1.at(i) + p.at(i);
  }
  sort(sum2.begin(), sum2.end());
  
  double A = (0.5*K + 1.0*sum2.at(N-K)/2);
  printf("%.8lf\n", A);
}
  
  
  
    
    