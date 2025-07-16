#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,N,r,s=0;
  cin>>n;
  N=n;
  while(n>0){
    r=n%10;
    s+=r;
    n/=10;
  }
  if(N%s==0){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}