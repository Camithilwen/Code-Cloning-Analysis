#include <bits/stdc++.h>
using namespace std;

vector< int64_t > divisor(int64_t n) {
  vector< int64_t > ret;
  for(int64_t i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  return (ret);
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);

    int64_t n,a,b,c; cin>>n>>a>>b; if(n==3)cin>>c;
    vector<int64_t> v;
    for(auto t:divisor(a))if(!(b%t))v.push_back(t);
    if(n==3)for(auto t:v)if(c%t)v.erase(find(v.begin(),v.end(),t));
    sort(v.begin(),v.end());
    for(auto t:v)cout<<t<<'\n';
}
