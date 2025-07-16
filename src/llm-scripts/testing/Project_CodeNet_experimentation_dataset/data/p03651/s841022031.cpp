#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  bool contains_odd = false;
  bool contains_even = false;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.rbegin(), A.rend());
  ll g = gcd(A[0], A[1]);
  for (int i = 2; i < N; i++) {
    g = gcd(g, A[i]);
  }
  if (K % g == 0 && K <= A[0]) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}