#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
typedef long long ll;
long long mod = 1e9 + 7;
const int iINF = 0x3f3f3f3f;
const long long INF = 1LL << 60;

using namespace std;
using pint = pair<int, int>;

template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(200005);

  rep(i, n)
  {
    cin >> a[i];
  }

  rep(i, min(50, k))
  {

    vector<int> b(200005, 0);
    rep(j, n)
    {
      // 累積和
      int left = max(0, j - a[j]);
      int right = min(n - 1, j + a[j]);
      // cout << "===" << endl;
      // cout << left << right << endl;

      b[left]++;
      b[right + 1]--;
    }

    // cout << b[0] << " ";
    repi(i, 1, n)
    {
      // cout << b[i] << " ";
      b[i] += b[i - 1];
    }
    // cout << endl;
    a = b;
  }

  rep(i, n)
  {
    cout << a[i] << " ";
  }

  return 0;
}
