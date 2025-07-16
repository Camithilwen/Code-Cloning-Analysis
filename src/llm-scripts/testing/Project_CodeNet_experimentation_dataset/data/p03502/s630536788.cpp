#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n; cin >> n;
  int a;
  string s = to_string(n);
  for (char c : s)
  {
    a += (c - '0');
  }
  if (!(n % a))
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  
  
}