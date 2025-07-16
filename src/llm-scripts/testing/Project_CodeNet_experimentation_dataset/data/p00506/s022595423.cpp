#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a,b,c = 100000001;
  if(n == 2)cin >> a >> b;
  if(n == 3)cin >> a >> b >> c;
  int mn = min(a,min(b,c));
  if(n == 2)c = 0;
  for(int i = 1 ; i <= mn ; i++ ){
    if(a%i == 0 && b%i == 0 && c%i == 0)cout << i << endl;
  }
  return 0;
}