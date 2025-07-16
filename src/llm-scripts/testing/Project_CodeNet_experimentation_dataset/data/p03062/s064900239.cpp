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
  int N;
  cin >> N;
  vector<ll> A(N);
  int count = 0;
  ll m = P;
  rep(i,N) 
  {
    cin >> A[i];
    if(A[i]<0)
    {
      count ++;
      A[i] = -1 * A[i];
    }
    m = min(m,A[i]);
  }
  ll sum = 0;
  rep(i,N) 
  {
    sum += A[i];
  }
  if(count%2==0)
  {
    cout << sum << endl;
  }
  else
  {
    cout << sum - m * 2 << endl;
  }
  return 0;
}
