#include <bits/stdc++.h>
using namespace std;
 
 
void solve(){
  int main,temp,count=0;
  cin>>main;

  temp=floor(main/500);
  main=main-temp*500;
  count=count+temp*1000;
  count=count+floor(main/5)*5;
  cout<<count;
  return;

}



int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t=1;
  //cin>>t;
  while(t--) solve();
}
