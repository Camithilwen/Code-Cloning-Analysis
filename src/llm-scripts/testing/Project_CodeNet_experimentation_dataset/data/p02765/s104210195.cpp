#include<iostream>
using namespace std;
int main(){
  int a, b, c;
  cin >> a >> b;
  if(a >= 10){
    cout << b << "\n";
  }
  else{
    c = b + 100 * (10 - a);
    cout << c << "\n";
  }
}