#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll X;
  cin>>X;
  ll a=X/500;
  X-=500*a;
  cout<<1000*a+5*(X/5)<<endl;
}
