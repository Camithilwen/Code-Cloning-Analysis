#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,n,i=0;
  cin >> a >> b;
  n = 1;
  while(b>n){
    n += a - 1;
    i++;
  }
  
  cout << i << endl;
}