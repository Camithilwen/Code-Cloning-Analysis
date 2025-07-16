#include <bits/stdc++.h>
using namespace std;

int main(){
int n,k;
  cin >> n >> k;
int x[n]; 
  for(int i=0;i<n;i++){
  cin >> x[i];
  }
  sort(x,x+n,greater<int>());
int sum=0;
  for(int i=0;i<k;i++){
  sum+=x[i];
  }
  cout << sum << endl;
}