#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)


int main(){
  int n;
  cin >> n;
  vector<int> l(2*n);
  int sum =0;
  rep(i,2*n){
    cin >> l[i];
  }
  rep(i,2*n){
    rep(j,2*n-i-1){
      int temp;
      if(l[j]>l[j+1]){
        temp =l[j];
        l[j] = l[j+1];
        l[j+1]=temp;
      }
    }
  }
  rep(i,n){
    sum +=l[2*i];
  }
  cout << sum << endl;
  return 0;
}
