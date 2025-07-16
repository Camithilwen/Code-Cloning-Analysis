#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main()
{
  int n;
  cin >> n;
  
  int p[n];
  rep(i,n) cin >> p[i];
  
  int min = 1e9;
  int ans = 0;
  for(int i = 0; i < n; i++){
    if(p[i] <= min){
      min = p[i];
      ans++;
    }
  }
  
  cout << ans << endl;
      
}