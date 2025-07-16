#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> A(N), sumA(N+1, 0);
  long long mod_ = 1000000007;
  for (int i=0; i<N; i++){
    cin >> A.at(i);
    sumA.at(i+1) = sumA.at(i)+A.at(i);
    if (sumA.at(i+1) >= mod_) sumA.at(i+1) %= mod_;
  }
  
  long long ans = 0;
  long long sum_comp = 0;
  for (int i=0; i<N-1; i++){
    sum_comp = sumA.at(N) > sumA.at(i+1) ? sumA.at(N)-sumA.at(i+1) : sumA.at(N)+mod_-sumA.at(i+1);
    ans += A.at(i)*sum_comp;
    if (ans >= mod_) ans %= mod_;
  }
  
  cout << ans << endl;
}
