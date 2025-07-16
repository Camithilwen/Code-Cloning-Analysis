#include<bits/stdc++.h>
using namespace std;
int nearPow2(int n){
  if (n <= 0) return 0;
  if ((n & (n - 1)) == 0) return (uint)n;
  uint ret = 1;
  while (n > 0) { ret <<= 1; n >>= 1; }
  return ret;
}
int main(){
  int n,ans=0;
  cin >> n;
  map<int,int> mp;
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    mp[a]++;
  }
  auto itr=mp.end();
  itr--;
  for(;itr!=mp.begin();itr--){
    int pw=nearPow2((*itr).first);
    if(pw == (*itr).first){
      ans += (*itr).second/2;
    }
    else{
      int q = min((*itr).second,mp[pw-(*itr).first]);
      ans += q;
      mp[pw-(*itr).first] -= q;
    }
  }
  int pw=nearPow2((*itr).first);
  if(pw == (*itr).first){
    ans += (*itr).second/2;
  }
  cout << ans << endl;
}