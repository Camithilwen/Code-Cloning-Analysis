#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
  ll n; cin >> n;
  ll a = n/500;
  n %= 500;
  cout << (a*1000) + int(n/5)*5 << endl;
  return 0;
}