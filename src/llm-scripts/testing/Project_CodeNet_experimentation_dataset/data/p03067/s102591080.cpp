using namespace std;
#include <iostream>
#include <vector>
int A,B,C;

int main() {
  cin >> A >> B >> C;
  string ans = (A < C) ^ (B < C)?"Yes":"No";
  cout << ans << endl; 
  return 0;
}