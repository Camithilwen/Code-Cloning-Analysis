#include<bits/stdc++.h>
using namespace std;
int main(){
  int q,z,y=0;
  cin>>q;
  z=q;
  while(z>0){
    y+=z%10;
    z/=10;
  }
  if(q%y==0) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}