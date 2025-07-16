#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int cpN = N;
  int sum = 0;
  
  while(cpN > 0){ 
    sum += cpN % 10;
    cpN /= 10;
  }
  
  if(N % sum == 0)cout << "Yes" << endl;
  else cout << "No" << endl;
 
}