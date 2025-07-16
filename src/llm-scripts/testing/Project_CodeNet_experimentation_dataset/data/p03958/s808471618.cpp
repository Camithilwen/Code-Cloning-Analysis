#include<bits/stdc++.h>
using namespace std;
int main(){
  int k,n;
  cin >> k >> n;
  int a[n];
  int d=0,e;
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(d<a[i]){
      d=a[i];
      e=i;
    }
  }
  cout << max(a[e]- 1 -(k-a[e]),0);
}
