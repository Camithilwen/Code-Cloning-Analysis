#include <bits/stdc++.h>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
using namespace std;

using lli = long long int;
void YESNO(bool), YesNo(bool);
template <class T1, class T2>
bool chmin(T1 &l, const T2 &r);
template <class T1, class T2>
bool chmax(T1 &l, const T2 &r);

lli sum[200005] = {};
lli rec(lli l, lli r)
// [l, r)
{
  return sum[r] - sum[l];
}
bool pivot(lli l, lli r, lli piv)
{
  //  assert(l <= piv + 1 && piv < r - 1);
  return rec(piv, r) - rec(l, piv) >= 0;
}
lli calc(int l, int r, int piv)
{
  return rec(piv, r) - rec(l, piv);
}
int good(int l, int r, int piv1, int piv2)
{
  if (abs(calc(l, r, piv1)) < abs(calc(l, r, piv2)))
    return piv1;
  return piv2;
}
pair<lli, lli> calc(lli l, lli r)
{
  lli low = l + 1, up = r;
  while (up - low > 1)
  {
    lli mid = (up + low) / 2;
    if (pivot(l, r, mid))
    {
      low = mid;
    }
    else
    {
      up = mid;
    }
  }
  int go = good(l, r, low, up);
  return make_pair(rec(l, go), rec(go, r));
}
void solve(long long N, std::vector<long long> A)
{
  rep(i, N) sum[i + 1] = sum[i] + A[i];
  lli ans = 1e18;
  for (int i = 2; i <= N - 2; i++)
  {
    // [0, i) , [i, N) に分割
    int ll = 0, lr = i;
    int rl = i, rr = N;
    auto ls = calc(ll, lr);
    auto rs = calc(rl, rr);
    chmin(ans, max({ls.first, ls.second, rs.first, rs.second}) - min({ls.first, ls.second, rs.first, rs.second}));
  }
  cout << ans << endl;
}

int main()
{
  long long N;
  scanf("%lld", &N);
  std::vector<long long> A(N);
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &A[i]);
  }
  solve(N, std::move(A));
  return 0;
}

// -- lib
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }

template <class T1, class T2>
bool chmin(T1 &l, const T2 &r)
{
  return (l > r) ? (l = r, true) : false;
}

template <class T1, class T2>
bool chmax(T1 &l, const T2 &r)
{
  return (l < r) ? (l = r, true) : false;
}