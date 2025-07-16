#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int S = 0;
  int a = 1;
  
  
  for (int i =0; i < 9; i++) {
    int x;
    a *= 10;
    x = (N % a - N % (a/10)) / (a/10);
    S += x;
  }
  
  if (N % S == 0){
  	cout << "Yes";
  } 
  else {
  	cout << "No";
  }
 
}