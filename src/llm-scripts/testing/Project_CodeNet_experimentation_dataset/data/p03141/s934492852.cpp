#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<ll> takahashi(n);
  ll sum = 0;
  for(int i = 0; i < n; i++){
    ll a, b;
    cin >> a >> b;
    takahashi[i] = a+b;
    sum-=b;
  }
  sort(takahashi.begin(), takahashi.end(), greater<long long>());
  for(int i = 0; i < n; i++){
    if(i%2 == 0){  
    sum += takahashi[i];
    }
  }
  cout << sum;
}
