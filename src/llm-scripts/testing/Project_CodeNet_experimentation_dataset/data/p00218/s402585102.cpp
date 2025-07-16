#include <bits/stdc++.h>
using namespace std;
int main(){
  int s,i,a,b,c;
  while(cin>>s,s){
  while(s--){
    cin>>a>>b>>c;
    if(a==100||b==100||c==100||b+c>179||a+b+c>239)cout<<'A'<<endl;
    else if(a+b+c>209||(a+b+c>149&&(a>79||c>79)))cout<<'B'<<endl;
    else cout<<'C'<<endl;
  }}
}