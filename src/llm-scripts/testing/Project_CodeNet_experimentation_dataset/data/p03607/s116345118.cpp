#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const ll MOD = 1000000007;
using pint = pair<ll, ll>;

int main() {
  ll N;
  cin >> N;
  map<ll, ll> A;
  for (int i = 0; i < N; i++){
    ll tmp = 0;
    cin >> tmp;
    A[tmp]++;
  }
  ll cnt = 0;
  for (auto i : A){
    if (i.second % 2 == 0) continue;
    else{
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}