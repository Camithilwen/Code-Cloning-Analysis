#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int N, mcount=0;
  cin >> N;
  long long A[N];
  for (int i = 0; i < N; i++){
    cin >> A[i];
    if (A[i]<0){
      mcount++;
      A[i] *= -1;
    }
  }

  long long ans = 0;
  if (mcount%2==0){
    for (int i = 0; i < N; i++){
      ans += A[i];
    }
    printf("%llu\n", ans);
  }else{
    sort(A, A+N);
    for (int i = 1; i < N; i++){
      ans += A[i];
    }
    printf("%llu\n", ans - A[0]);
  }
  
}
