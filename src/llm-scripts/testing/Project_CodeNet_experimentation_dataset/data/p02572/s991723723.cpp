#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;

int main(){
  int N;
  cin >> N;
  vector<long long> A(N);
  for(int i = 0; i < N; i++)
    cin >> A[i];
  long long ans = 0;
  long long sum = 0;
  long long sum2 = 0;
  
  for(int i = 0; i < N; i++){
    sum2 = (sum2 + A[i]*A[i]) % (2*mod);
    sum = (sum + A[i]) % (2*mod);
  }
  
  ans = (sum*sum - sum2)  % (2*mod) / 2;
  
  cout << ans << endl;
}
