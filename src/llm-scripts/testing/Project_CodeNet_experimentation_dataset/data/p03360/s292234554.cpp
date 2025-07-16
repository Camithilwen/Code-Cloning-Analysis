#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b,c,k,m,mk; cin>>a>>b>>c>>k;
  m=max({a,b,c}); mk=m;
  for(int i=0; i<k; i++) mk*=2; 
  cout<<a+b+c-m+mk;
}