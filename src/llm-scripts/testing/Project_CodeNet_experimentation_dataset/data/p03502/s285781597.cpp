#include <bits/stdc++.h>
using namespace std;

int main() {
  int N=0, a=0, b=0, c=10;
  cin >> N;
  
  a = N % c;
  for(int i=0; i<8; i++){
    if(c > N){
      break;
    }
    b = N / c;
    a += b % 10 ;
    c = c * 10;
  }
  
  if(N % a == 0){
    cout << "Yes" << endl;
  }
  else{
   cout << "No" << endl;
  } 
}