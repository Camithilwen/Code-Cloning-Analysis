#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t a,b;
  cin >> a >> b;
  vector<pair<int64_t,int64_t>> res;
  int64_t n=gcd(a,b);
  for(int64_t i=2;i*i<=n;i++){
    if(n%i!=0)continue;
    int64_t s=0;
    while(n%i==0){
      s++;
      n/=i;
    }
    res.push_back({a,s});
  }
  if(n!=1)res.push_back({n,1});
  cout << res.size()+1 << endl;
}
      
  