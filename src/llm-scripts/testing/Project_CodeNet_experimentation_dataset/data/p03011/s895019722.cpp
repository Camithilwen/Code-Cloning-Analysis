#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  vector<ll>vec(3);
  ll a=0;
  for(ll i=0;i<3;i++){
    cin>>vec.at(i);
    a+=vec.at(i);
  }
  sort(vec.begin(),vec.end());
  cout<<a-vec.at(2)<<endl;
  return 0;
}
