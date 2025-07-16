#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N, M;
  cin >> N >> M;
  int max = 0;
  if(M%N == 0){
    cout << M / N <<endl;
    return 0;
  }
  for(int i = 1; i <= M/N; i++){
    if(M % i == 0 && M % i <= N){
      max = i;
    }
  }
  cout << max <<endl; 
}
