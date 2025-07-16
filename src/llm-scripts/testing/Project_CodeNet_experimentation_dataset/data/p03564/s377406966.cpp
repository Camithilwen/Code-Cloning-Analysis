#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin >> N >> K;
  int x;
  x = 1;
  
  for(int i = 0; i < N; i++){   
    if(2 * x > x + K)
    x = x + K;
    if(2 * x <= x + K)
    x = 2 * x;
  }
  cout << x << endl; 
}