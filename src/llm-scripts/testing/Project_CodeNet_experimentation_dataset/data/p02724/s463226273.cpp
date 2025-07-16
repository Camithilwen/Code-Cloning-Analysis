#include <bits/stdc++.h>
using namespace std;

int main(){
  int x;
  cin >> x;
  
  int big = x/500;
  int rest = x%500;
  int small = rest/5;
  
  cout << 1000*big + 5*small << endl;
}