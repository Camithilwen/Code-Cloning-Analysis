#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int N,K; cin >> N >> K;
  vector<ll> v(N+1,0);

  for(int i = 0; i < N; i++){
    ll tmp; cin >> tmp;
    v[i+1] = tmp;
  }

  for(int i = 1; i <= N; i++){
    v[i] = v[i] + v[i-1];
  }

  ll max_val = 0;
  for(int i = N; i - K >= 0; i--){
    max_val = max(max_val, v[i] - v[i - K]);
  }
  cout << (double)(max_val+K) / 2.0 << endl;

}
