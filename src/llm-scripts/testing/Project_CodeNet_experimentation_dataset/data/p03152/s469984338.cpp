#include<bits/stdc++.h>

const int mod = 1e9 + 7;

using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  
  vector<int> A(N), B(M);
  for(int i = 0; i < N; ++i) cin >> A[i];
  for(int j = 0; j < M; ++j) cin >> B[j];
  sort(A.begin(), A.end(), greater<int>());
  sort(B.begin(), B.end(), greater<int>());
  
  long long p = 1;
  for(int d = N * M, i = 0, j = 0; d; --d){
    if(i < N && j < M && A[i] == d && B[j] == d){
      ++i; ++j;
    }else if(i < N && A[i] == d){
      p *= j;
      ++i;
    }else if(j < M && B[j] == d){
      p *= i;
      ++j;
    }else{
      p *= (d - N * M + i * j);
    }
    p %= mod;
  }
  
  cout << (p + mod) % mod << endl;
  
  return 0;
}