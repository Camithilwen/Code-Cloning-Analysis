// darksta5's template v2.0

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class DisjointSet
{
private:
  int _sz, _numSets;
  vector<int> _par, _setSz, _rank;

public:
  DisjointSet(int sz)
  {
    _sz = sz;
    _numSets = sz;
    _setSz.assign(sz, 1);
    _rank.assign(sz, 0);
    _par.assign(sz, 0);
    for (int i = 0; i < sz; i++)
    {
      _par[i] = i;
    }
  }

  int sz()
  {
    return _sz;
  }

  int numSets()
  {
    return _numSets;
  }

  int setSz(int i)
  {
    return _setSz[find(i)];
  }

  int find(int i)
  {
    int x = i;
    while (x != _par[x])
    {
      x = _par[x];
    }

    return _par[i] = x;
  }

  bool isSame(int i, int j)
  {
    return find(i) == find(j);
  }

  void uni(int i, int j)
  {
    if (!isSame(i, j))
    {
      _numSets--;
      int x = find(i);
      int y = find(j);
      if (_rank[x] < _rank[y])
      {
        _par[x] = y;
        _setSz[y] += _setSz[x];
      }
      else
      {
        _par[y] = x;
        _setSz[x] += _setSz[y];
        if (_rank[x] == _rank[y])
        {
          _rank[x]++;
        }
      }
    }
  }
};

ll make_key(int x, int y)
{
  return (ll)x * 200050LL + (ll)y;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, r1, r2;
  cin >> n >> r1 >> r2;
  DisjointSet ds1(n), ds2(n);

  for (int i = 0; i < r1; i++)
  {
    int x, y;
    cin >> x >> y;
    ds1.uni(x - 1, y - 1);
  }

  for (int i = 0; i < r2; i++)
  {
    int x, y;
    cin >> x >> y;
    ds2.uni(x - 1, y - 1);
  }

  unordered_map<ll, int> cnt;
  for (int i = 0; i < n; i++)
  {
    ll key = make_key(ds1.find(i), ds2.find(i));
    cnt[key]++;
  }

  for (int i = 0; i < n; i++)
  {
    ll key = make_key(ds1.find(i), ds2.find(i));
    if (i < n - 1)
    {
      cout << cnt[key] << " ";
    }
    else
    {
      cout << cnt[key] << endl;
    }
  }
}