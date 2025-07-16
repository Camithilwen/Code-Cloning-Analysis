#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
  int n,k;
  cin >> n >> k;
  
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  
  vector<int> b(n+1);
  vector<int> c(n);
  int count = 0;
  
  for(int i=1; i<=k; i++){
   
      for(int i=0; i<n; i++){
        b[max(1,1+i-a[i])-1]++;
        b[min(n,1+i+a[i])]--;    
      }
    
      for(int i=0; i<n; i++){
        if(i == 0) c[i] = b[i];
        else c[i] += c[i-1] + b[i];
      }
    
      for(int i=0; i<n; i++){
       a[i] = c[i];
       b[i] = 0;
       c[i] = 0;
      }
    
      for(int i=0; i<n; i++){
        if(a[i] == n) count++;
     }
      
     if(count == n){
            break;
     }
      
        count = 0;
   
  }
  
  if(n == 1) cout << a[0] << endl;
  else{
    for(int i=0; i<n-1; i++) cout << a[i] << " ";
    cout << a[n-1] << endl;
  }
	return 0;
}
