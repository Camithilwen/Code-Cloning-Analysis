#include<bits/stdc++.h>
using namespace std;
int main(){
  int d,t,s;
  cin>>d>>t>>s;
  float time = (d/(s*1.0));
  if(time<=t)
    cout<<"Yes"<<endl;
  else 
    cout<<"No"<<endl;
return 0;
}