#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, a, b, c, d, ans = 0;
  cin >> N;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> A, B;
  for (int i = 0; i < N; i++)
  {
    cin >> a >> b;
    A.push(make_pair(a, b));
  }
  for (int i = 0; i < N; i++)
  {
    cin >> c >> d;
    B.push(make_pair(c, d));
  }
  priority_queue<pair<int, int>> ayx;
  for (int x = 0; x < 2 * N; x++)
  {
    if (B.top().first != x)
      continue;
    int bx, by;
    tie(bx, by) = B.top();
    B.pop();
    while (!A.empty() && A.top().first < x)
    {
      ayx.emplace(make_pair(A.top().second, A.top().first));
      A.pop();
    }
    queue<pair<int, int>> tmp;
    while (!ayx.empty())
    {
      if (ayx.top().second < bx && ayx.top().first < by)
      {
        ayx.pop();
        ans++;
        break;
      }
      else
      {
        tmp.push(ayx.top());
        ayx.pop();
      }
    }
    while (!tmp.empty())
    {
      ayx.push(tmp.front());
      tmp.pop();
    }
  }
  cout << ans << endl;
}