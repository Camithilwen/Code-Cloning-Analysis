#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

bool check(int n){
  double rn=sqrt(n);
  if(rn==(int)rn)return true;
  else return false;
}

int main(){
  int n;
  cin >> n;
  rep(i,n){
    if(check(n-i)){
      cout << n-i << endl;
      return 0;
    }
  }
  cout << 1 << endl;
}