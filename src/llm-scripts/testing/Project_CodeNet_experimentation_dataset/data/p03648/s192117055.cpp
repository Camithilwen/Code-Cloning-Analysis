#include <iostream>
#include <vector>

using namespace std;

int simulate(vector<long long int> A){
  int N = A.size(), ret = 0;
  while(1){
    int t = 0;
    for(int i = 0; i < N; ++i){
      if(A[i] > A[t]) t = i;
    }
    if(A[t] < N) break;
    for(int i = 0; i < N; ++i){
      if(i != t) ++A[i];
      else A[i] -= N;
    }
    ++ret;
  }
  return ret;
}

int main(){
  long long int K, M = 1e16 + 1e3 + 1;
  cin >> K;
  vector<long long int> A(50);
  for(long long int i = 0; i < 50; ++i) A[i] = i + K/50;
  K %= 50;
  for(int i = 0; i < K; ++i) ++A[49-i];
  //cout << simulate(A) << endl;
  cout << 50 << endl;
  cout << A[0];
  for(int i = 1; i < 50; ++i) cout << " " << A[i];
  cout << endl;
  return 0;
}
