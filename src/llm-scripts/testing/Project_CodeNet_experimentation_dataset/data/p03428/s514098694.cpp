#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
double pi = 3.1415926535897932384646433;
typedef long long ll;
typedef pair<ll, ll>pii;
ll ccw(pii a, pii b, pii c)
{
  return (b.first - a.first)*(c.second - b.second) - (b.second - a.second)*(c.first - b.first);
}
double dist(pii a, pii b)
{
  return sqrt(double((b.first - a.first)*(b.first - a.first) + (b.second - a.second)*(b.second - a.second)));
}
double dot(pii a, pii b)
{
  return double(a.first*b.first + a.second*b.second);
}
double ans[111];
int main()
{
  fill(ans, ans + 111, 0);
  int num;
  scanf("%d", &num);
  vector<pii>v;
  map<pii, int>ma;
  for (int i = 0; i < num; i++)
  {
    ll a, b;
    scanf("%lld%lld", &a, &b);
    v.push_back(make_pair(a, b));
    ma[make_pair(a, b)] = i;
  }
  sort(v.begin(), v.end());
  vector<pii>v1, v2;
  for (int i = 0; i < num; i++)
  {
    for (;;)
    {
      if (v1.size() <= 1)break;
      pii a = v1[v1.size() - 2], b = v1[v1.size() - 1];
      if (ccw(a, b, v[i])<0)v1.pop_back();
      else break;
    }
    v1.push_back(v[i]);
  }
  for (int i = 0; i < num; i++)
  {
    for (;;)
    {
      if (v2.size() <= 1)break;
      pii a = v2[v2.size() - 2], b = v2[v2.size() - 1];
      if (ccw(a, b, v[i])>0)v2.pop_back();
      else break;
    }
    v2.push_back(v[i]);
  }
  for (int i = int(v2.size()) - 2; i >= 1; i--)v1.push_back(v2[i]);
  for (int i = 0; i < v1.size(); i++)
  {
    pii s = v1[(i + v1.size() - 1) % v1.size()];
    pii t = v1[i];
    pii u = v1[(i + 1) % v1.size()];
    //printf("%lld %lld  %lld %lld  %lld %lld\n", s.first, s.second, t.first, t.second, u.first, u.second);
    double x = acos(dot(make_pair(u.first - t.first, u.second - t.second), make_pair(s.first - t.first, s.second - t.second)) / dist(s, t) / dist(t, u));
    ans[ma[v1[i]]] = (pi - x) / (2 * pi);
  }
  for (int i = 0; i < num; i++)printf("%.6lf\n", ans[i]);
}
