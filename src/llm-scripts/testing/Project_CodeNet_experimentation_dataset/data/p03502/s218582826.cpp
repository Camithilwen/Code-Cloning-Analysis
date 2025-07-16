#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,x;
  cin >> N;
  x = N%10 + ((N%100) / 10) + ((N%1000) / 100 ) + ((N%10000) / 1000) + ((N%100000) / 10000) + ((N%1000000) / 100000) + ((N%10000000)/1000000)+((N%1000000000) / 10000000);
  if(N%x == 0)
    cout << "Yes" << endl;
    
  if(N%x != 0){
    cout << "No" << endl;
  }
}