#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  rep(i,10){
    int cnt = 0;
    if(i==a)cnt++;
    if(i==b)cnt++;
    if(i==c)cnt++;
    if(cnt==2){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
