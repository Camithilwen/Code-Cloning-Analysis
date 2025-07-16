#include <bits/stdc++.h>
using namespace std;
 
int main(){
  long long int n, a, b;
  cin >> n >> a >> b;
  long long int x[n], diff[n]={};
  long long int ans=0;
  for(int i=0; i<n; i++){
    cin >> x[i];
    if(i==0) continue;
    if((x[i]-x[i-1])*a<b) ans += (x[i]-x[i-1])*a;
    else ans += b;
  }
  
  cout << ans << endl;
  return 0;
}

