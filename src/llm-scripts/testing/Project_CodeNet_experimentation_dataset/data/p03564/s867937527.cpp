#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int sum=1;
  
  for(int i=0; i<N; i++){
    if(sum*2 > sum+K) sum+=K;
    else sum*=2;
  }
  
  cout << sum << endl;
  
  return 0;
}
