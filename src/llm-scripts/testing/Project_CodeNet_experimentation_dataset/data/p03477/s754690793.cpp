#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, d;
  cin>>a>>b>>c>>d;
  string ans;
  if(a+b>c+d){
    ans="Left";
  }
  else if(a+b<c+d){
    ans="Right";
  }
  else{
    ans="Balanced";
  }
  cout<<ans<<endl;
}