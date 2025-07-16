#include <bits/stdc++.h>
using namespace std;

int main() {
  int board = 1;
  int N, K;
  cin >> N >> K;
  
  int i;
  for(i = 0; i < N; i++){ 
    if(board > K)
      break;
    board *= 2;
  }
  for(;i < N; i++)
    board += K;
    
  cout << board << endl;
}