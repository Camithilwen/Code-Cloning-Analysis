#include <iostream>
using namespace std;

int main()
{
  int x, coin500, coin5;
  cin >> x;
  coin500 = x / 500;
  x -= coin500 * 500;
  coin5 = x / 5;
  cout << coin500 * 1000 + coin5 * 5 << endl;
  return 0;
}