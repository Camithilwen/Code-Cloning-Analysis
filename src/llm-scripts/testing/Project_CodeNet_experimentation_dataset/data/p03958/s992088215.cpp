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
  int K,T;
  cin >> K >> T;
  vector<int> a(T);
  rep(i,T) cin >> a[i];
  sort(ALL(a));
  int sum = 0;
  rep(i,T-1)
  {
    sum += a[i];
  }
  if(sum>a[T-1])
  {
    cout << 0 << endl;
  }
  else
  {
    cout << a[T-1] - sum - 1 << endl;
  }
  return 0;
}
