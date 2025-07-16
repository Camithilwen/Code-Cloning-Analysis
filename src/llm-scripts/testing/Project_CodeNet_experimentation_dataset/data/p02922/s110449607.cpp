#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  if((b - 1) % (a - 1) == 0){
    cout << (b - 1) / (a - 1) << endl;
  } else{
    cout << (b - 1) / (a - 1) + 1 << endl;
  }
  return 0;
}