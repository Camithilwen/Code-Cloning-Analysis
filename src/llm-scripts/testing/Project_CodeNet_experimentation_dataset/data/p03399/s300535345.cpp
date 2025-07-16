#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  if(a >= b){
    a = b;
  }
  if(c >= d){
    c = d;
  }
  cout<<a+c<<'\n';
  return 0;
}
