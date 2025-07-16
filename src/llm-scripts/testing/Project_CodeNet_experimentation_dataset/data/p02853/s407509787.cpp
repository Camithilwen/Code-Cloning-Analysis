#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ll long long
using namespace std;

const ll P = 1000000007;
const long long INF = 1LL << 60;
int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main()
{
  cout << fixed << setprecision(10);
  int X,Y;
  cin >> X >> Y;
  if(X==1&&Y==1)
  {
    cout << 1000000 << endl;
    return 0;
  }
  int sum = 0;
  if(X==1)
  {
    sum += 300000;
  }
  else if(X==2)
  {
    sum += 200000;
  }
  else if(X==3)
  {
    sum += 100000;
  }
  if(Y==1)
  {
    sum += 300000;
  }
  else if(Y==2)
  {
    sum += 200000;
  }
  else if(Y==3)
  {
    sum += 100000;
  }
  cout << sum << endl;
  return 0;
}
