#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t n,k;
  cin >> n >> k;
  if(k!=0){
    cout << "0\n";
    return 0;
  }
  vector<int64_t>a(n-1);
  for(int i=0;i<n-1;i++){
    cin >> k;
    if(k==0){
      cout << "0\n";
      return 0;
    }
    a.at(k-1)++;
  }
  int64_t ans=1;
  for(int i=0;i<n-2;i++){
    int64_t m=1;
    for(int j=0;j<a.at(i+1);j++){
      m*=a.at(i);
      m%=998244353;
    }
    ans*=m;
    ans%=998244353;
  }
  cout << ans << endl;
  return 0;
}