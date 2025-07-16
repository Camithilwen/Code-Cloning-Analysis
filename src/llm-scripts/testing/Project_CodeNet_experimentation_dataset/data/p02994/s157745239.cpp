#include<bits/stdc++.h>

using namespace std;


int main(){
  int N, L;
  cin >> N >> L;
  
  int eated_apple = 10000000;
  int sum_taste = 0;
  for(int i=1; i<=N; i++){
    sum_taste += L+i-1;
    if(abs(eated_apple)>abs(L+i-1)) eated_apple = L+i-1;
  }
  
  cout << sum_taste-eated_apple << endl;
  
  return 0;
}