#include <iostream>

using namespace std;

int main()	{
  long long x;
  cin >> x;
  long long moves = 2 * (x / 11);
  if (x % 11 > 0)	moves++;
  if (x % 11 > 6)	moves++;
  cout << moves << endl;
  return 0;
}