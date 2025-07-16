#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

template <typename T>
void printlnVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << endl;
  }
}

template <typename T>
void printVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{
  int N;
  cin >> N;
  priority_queue<long long> point_add;
  long long sumA = 0;
  rep(i, N)
  {
    long long A, B;
    cin >> A >> B;
    point_add.push(A + B);
    sumA += A;
  }
  long long ans = sumA;
  bool turn_is_takahashi = true;
  while (point_add.size())
  {
    if (!turn_is_takahashi)
      ans -= point_add.top();
    turn_is_takahashi = !turn_is_takahashi;
    point_add.pop();
  }
  cout << ans << endl;
  return 0;
}