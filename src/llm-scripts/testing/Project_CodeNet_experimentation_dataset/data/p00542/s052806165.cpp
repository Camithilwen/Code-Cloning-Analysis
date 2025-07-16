#include <bits/stdc++.h>
using namespace std;

int main()
{
  int sum = 0;
  int a, b, m = 101;

  for (int i = 0; i < 4; i++){
    cin >> a;
    m = min(a, m);
    sum += a;
  }

  sum -= m;

  cin >> a >> b;

  sum += max(a, b);

  cout << sum << endl;
}