#include <bits/stdc++.h>
using namespace std;
int main(){
  long long a,b;	cin >> a >> b;
  long long x=__gcd(a,b);
  
  int ans=1;
  for(long long i=2;i*i<x;i++){
    if(x%i!=0)	continue;
    ans++;
    while(x%i==0){
      x/=i;
    }
  }
  if(x!=1)	ans++;
  cout << ans;
}