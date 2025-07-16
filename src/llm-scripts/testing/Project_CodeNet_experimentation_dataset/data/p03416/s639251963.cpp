#include <bits/stdc++.h>
using namespace std;
int main()
  {int A, B, c{}; cin >> A >> B;
  for (int i{A}; i <= B; ++i)
    {auto s{to_string(i)}, t{s}; reverse(begin(t), end(t));
    c += s == t;}
  cout << c;}