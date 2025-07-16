#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define fsp(x) cout << fixed << setprecision(x)
const ll inf = LLONG_MAX;
const long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
  ll n;
  cin >> n;
  vector<vll> a(n, vll(2));
  long double avg = 0;
  for (ll i = 0; i < n; i++) {
    cin >> a[i][0];
    avg += a[i][0];
    a[i][1] = i;
  }
  avg /= n;
  ll m = -1;
  sort(all(a));
  for (ll i = 0; i < n; i++) {
    if (a[i][0] == avg) {
      cout << a[i][1] << endl;
      return 0;
    }
    if (a[i][0] > avg) {
      while (i > 0 && a[i][0] == a[i - 1][0]) i--;
      m = i;
      break;
    }
  }
  if (m == 0) {
    cout << a[m][1] << endl;
    return 0;
  }
  ll x = m - 1;
  while (x > 0 && a[x][0] == a[x - 1][0]) x--;
  //cout << a[m][0] - avg << " " << avg - a[x][0] << endl;
  if (a[m][0] - avg > avg - a[x][0]) cout << a[x][1] << endl;
  else if (a[m][0] - avg < avg - a[x][0]) cout << a[m][1] << endl;
  else {
    cout << min(a[x][1], a[m][1]) << endl;
  }
}