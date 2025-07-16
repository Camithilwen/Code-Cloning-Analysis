#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin>>n;
  
  ll ans=0;
  for(ll i=1; i*i<=n; i++){
    ans=i*i;
  }
  
  cout << ans;
}