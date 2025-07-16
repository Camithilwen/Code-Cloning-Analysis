#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define EACH(i, a) for (auto &&i : a)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define RFOR(i, a, b) for (int i = (int)b - 1; i >= (int)a; --i)
#define REP(i, n) FOR(i, 0, n)
#define REPS(i, n) FOR(i, 1, int(n) + 1)
#define RREP(i, n) RFOR(i, 0, n)
#define RREPS(i, n) RFOR(i, 1, int(n) + 1)
#define ALL(x) (x).begin(), (x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define debug(x) cout << #x << ": " << x << endl

#define pb push_back
#define mp make_pair
#define F first
#define S second

#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define INF (1L << 30)
#define MOD (1000000007)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

template <class T>
void pv(T a, T b)
{
  for (T i = a; i != b; ++i)
    cout << *i << " ";
  cout << endl;
}
template <class T>
void pvp(T a, T b)
{
  for (T i = a; i != b; ++i)
    cout << "(" << i->first << ", " << i->second << ") ";
  cout << endl;
}
template <class T>
bool chmax(T &a, const T &b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
  if (b < a)
  {
    a = b;
    return 1;
  }
  return 0;
}
int in()
{
  int x;
  scanf("%d", &x);
  return x;
}

using ll = long long;
#define int ll

//**********

signed main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  // A[i]: member i が j 番目に好きなスポーツ
  vector<int> A[301];

  REP(i, n)
  {
    REP(j, m)
    {
      int sp;
      cin >> sp;
      A[i].pb(sp - 1);
    }
  }

  int best_members = 999;

  if (m == 1)
  {
    best_members = n;
  }

  REP(ii, m - 1)
  {
    int popular[301];
    MEMSET(popular, 0);
    REP(i, n)
    { // popular[m]はm番目のスポーツの参加人数
      popular[A[i][0]] += 1;
    }
    int max_sp = 0;
    int max_members = 0;
    REP(sp, m)
    {
      if (max_members < popular[sp])
      {
        max_sp = sp;
        max_members = popular[sp];
      }
    }

    // debug(max_sp + 1);
    // debug(max_members);

    REP(i, n)
    { // 最大人気スポーツを除外
      A[i].erase(remove(ALL(A[i]), max_sp), A[i].end());
    }

    if (best_members > max_members)
    { // もし最大人数が、これまでで最小だったら更新
      best_members = max_members;
    }
  }

  cout << best_members << endl;

  return 0;
};
