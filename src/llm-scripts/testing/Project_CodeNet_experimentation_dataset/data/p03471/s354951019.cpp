#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N,Y;
  cin >> N >> Y;
  
  int ansi=-1, ansj=-1, ansk=-1;
  
  for(int i=0; i<=N; i++){
    for(int j=0; j<=N-i; j++){
      int k = N-i-j;
      int total = i*10000 + j*5000 + k*1000;
      if(total == Y){
        ansi = i;
        ansj = j;
        ansk = k;
      }
    }
  }
  
  cout << ansi << " " << ansj << " " << ansk << endl;
}
