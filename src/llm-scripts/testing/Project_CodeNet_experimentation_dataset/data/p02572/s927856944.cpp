#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll A[222222];
  ll N;
  cin >> N;
  ll i;
  for(i=0;i<=N-1;i++)
    cin >> A[i];
  ll sum[222222] = {0}; //sum[i]=A[i]までの和
  sum[0] = A[0];
  for(i=1;i<=N-1;i++){
    sum[i] = (sum[i-1] + A[i]) % 1000000007;
  }
  ll ans = 0;
  for(i=0;i<=N-2;i++)
    ans = (ans + A[i] * (sum[N-1] - sum[i])) % 1000000007;
  if(ans < 0) ans += 1000000007;
  cout << ans << endl;
}