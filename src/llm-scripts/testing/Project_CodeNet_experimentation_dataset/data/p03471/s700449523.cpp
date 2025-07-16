#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

void darts();

void longest_dis();

void sum_of_three_integers();

void otoshidama();

int main()
{
  //darts();
  //longest_dis();
  //sum_of_three_integers();
  otoshidama();
}


void darts()
{
  while (true)
  {
    int n, m;
    cin >> n >> m;

    // stop cond
    if (n == 0) break;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    // 2 darts combination
    // p = q, 0, p + q
    vector<int> q = p;
    q.push_back(0);
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j <= i; ++j)
      {
        q.push_back(p[i] + p[j]);
      }
    }

    sort(q.begin(), q.end());

    // q's size = 1 + n + n(n + 1) / 2
    //cout << q.size() << "\n";
    //for (auto x : q) cout << x << " ";

    int ret = 0;
    int j = q.size() - 1;
    //i:q linear scan
    for (int i = 0; i < q.size(); ++i)
    {
      if (q[i] > m) break;
      while (q[i] + q[j] > m) --j;
      ret = max(ret, q[i] + q[j]);
    }

    cout << ret << "\n";
  }
}

void longest_dis()
{
  int n;
  cin >> n;

  vector<pair<int, int>> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;

  double v_max = 0.0;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if ((p[i].first - p[j].first) * (p[i].first - p[j].first)
        + (p[i].second - p[j].second) * (p[i].second - p[j].second)
        >  v_max * v_max)
      {
        v_max = sqrt((p[i].first - p[j].first) * (p[i].first - p[j].first)
          + (p[i].second - p[j].second) * (p[i].second - p[j].second));
      }
    }
  }

  cout << v_max << "\n";
}

void sum_of_three_integers()
{
  int k, s;
  cin >> k >> s;

  int cnt = 0;
  //for (int i = 0; i <= k; ++i)
  //{
  //  for (int j = 0; j <= k; ++j)
  //  {
  //    for (int m = 0; m <= k; ++m)
  //    {
  //      if (i + j + m == s) ++cnt;
  //    }
  //  }
  //}
  for (int i = 0; i <= k; ++i)
  {
    for (int j = 0; j <= k; ++j)
    {
      int m = s - i - j;
      if (0 <= m && m <= k) ++cnt;
    }
  }

  cout << cnt << "\n";
}

void otoshidama()
{
  int n, Y;
  cin >> n >> Y;

  for (int x = 0; x <= n; ++x)
  {
    for (int y = 0; x + y <= n; ++y)
    {
      int z = n - x - y;
      if (x * 10000 + y * 5000 + z * 1000 == Y)
      {
        cout << x << " "<< y << " " << z << "\n";
        return;
      }
    }
  }

  cout << "-1 -1 -1\n";
}