#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;
  vector<P> ab(n), sum(n);
  for(int i=0; i<n; ++i){
    cin >> ab[i].first >> ab[i].second;
    sum[i].first = ab[i].first + ab[i].second;
    sum[i].second = i;
  }
  sort(sum.begin(),sum.end());
  reverse(sum.begin(),sum.end());
  ll ans = 0;
  for(int i=0; i<n; ++i){
    int x = sum[i].second;
    if(i%2 == 0){
      ans += ab[x].first;
    }else{
      ans -= ab[x].second;
    }
  }
  cout << ans << endl;
}