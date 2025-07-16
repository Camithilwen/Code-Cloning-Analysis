#include <iostream>
#include <string>
using namespace std;

int main(){
  string S;
  cin >> S;
  S.at(3) = '8';
  cout << S;
  return 0;
}