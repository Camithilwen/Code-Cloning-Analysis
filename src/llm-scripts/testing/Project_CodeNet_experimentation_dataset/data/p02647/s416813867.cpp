#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  
  for(int i = 0; i < min(k, 50); i++){
    vector<int> imos(n);	 //I'll begin the imos method
    for(int j = 0; j < n; j++){
      int l = max(0, j-a[j]);
      int r = min(n-1, j+a[j]);
      imos[l]++;
      if(r+1 <= n-1){
      	imos[r+1]--;
      }
    }
    for(int k = 0; k < n; k++){
      if(k > 0){
        imos[k] += imos[k-1];
      }
    }
    for(int l = 0; l < n; l++){
      a[l] = imos[l];
    }
    //a = imos;
  }
  
  for(int i = 0; i < n; i++){
    cout << a[i] << " ";
  }
}
