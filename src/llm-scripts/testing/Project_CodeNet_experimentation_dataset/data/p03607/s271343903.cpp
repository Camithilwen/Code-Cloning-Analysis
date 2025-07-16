#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t n;
  cin >> n;
  
  int64_t a[n+1];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  a[n] = 100000001;
    
  sort(a,a+n);
  int64_t ans = 0,count = 1;
  for(int i = 0; i < n; i++){
    if(a[i] == a[i+1]){
      count++;
    }else{
      if( (count % 2) == 1){
        ans++;
      }
      count = 1;
    }
  }

  cout << ans << endl;
}