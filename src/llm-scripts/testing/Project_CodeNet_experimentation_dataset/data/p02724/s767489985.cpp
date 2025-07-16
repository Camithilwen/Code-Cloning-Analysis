#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll X;
  cin >> X;
  
  ll c1=0;
  ll c2=0;
  while(X >= 500){
    X -= 500;
    c1++;
  }
  while(X >= 5){
    X -= 5;
    c2++;
  }
  cout << c1*1000+c2*5 << endl;
}
