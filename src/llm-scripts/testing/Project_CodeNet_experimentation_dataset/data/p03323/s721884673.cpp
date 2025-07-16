#include<iostream>
using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;
  
  if (a > 8 || b > 8) cout << ":(";
  else cout << "Yay!";
  
  return 0;
}