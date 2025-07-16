#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int r;

  cin >> r;

  if(r<1200)
    cout << "ABC";
  else if(r>=1200 && r<2800)
    cout << "ARC";
  else
  {
    cout << "AGC";
  }
}
