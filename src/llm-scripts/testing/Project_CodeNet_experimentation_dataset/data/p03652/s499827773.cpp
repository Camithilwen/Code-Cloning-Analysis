#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

ll N, M;

ll count_max(vector<queue<ll>>& A, vector<bool>& already)
{
  vector<ll> cnt(M, 0);
  for (ll i = 0; i < N; ++i) {
    while (true) {
      if (already.at(A.at(i).front())) {
        A.at(i).pop();
      }
      else {
        cnt.at(A.at(i).front()) += 1;
        break;
      }
    }
  }
  ll res = 0, index;
  for (ll i = 0; i < M; ++i) {
    if (res < cnt.at(i)) {
      index = i;
      res = cnt.at(i);
    }
  }
  already.at(index) = true;
  return res;
}

int main()
{
  cin >> N >> M;
  ll ans = INF;
  vector<bool> already(M, false);
  vector<queue<ll>> A(N);
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < M; ++j) {
      ll a;
      cin >> a;
      a -= 1;
      A.at(i).push(a);
    }
  }
  for (ll i = 0; i < M; ++i) {
    ans = min(ans, count_max(A, already));
  }
  cout << ans << endl;
}
