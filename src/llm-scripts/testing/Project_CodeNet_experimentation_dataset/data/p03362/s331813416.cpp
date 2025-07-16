#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<bool> prime(222220,true);
  for(int i=2; i<=222220; ++i) for(ll j=(ll)i*i; j<=222220; j += i){
    prime[j] = false;
  }
  vector<int> ans(n);
  int num = 0;
  for(int i=11; i<=55555; i += 5){
    if(!prime.at(i)) continue;
    ans[num] = i;
    ++num;
    if(num == n) break;
  }
  for(int i=0; i<n; ++i){
    if(i != n-1)cout << ans[i] << " ";
    else cout << ans[i] << endl;
  }
}