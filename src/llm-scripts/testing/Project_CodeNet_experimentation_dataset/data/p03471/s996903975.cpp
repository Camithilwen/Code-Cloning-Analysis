#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,y;
  cin >> n >> y;
  int tth=n,fth=0,th=0;
  bool ok=false;
  for(int i=0;i<=n;i++){
    tth=i;
    for(int j=0;j<=n-i;j++){
      fth=j;
      th=n-i-j;
      if(tth*10000+fth*5000+th*1000==y){
        ok=true;
        break;
      }
    }
    if(ok)
      break;
  }
  if(ok)
    cout << tth << " " << fth << " " << th << endl;
  else
    cout << "-1 -1 -1\n";
  return 0;
}