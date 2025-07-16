#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int x,y;
  cin>>x>>y;
  if(x==0 || y==0){
    if(y>x)
      cout<<y+abs(x)<<endl;
    else
      cout<<abs(y)+x+1<<endl;
  }else if(x*y>0){
    if(x<y)
      cout<<y-x<<endl;
    else
      cout<<x-y+2<<endl;
  }else if(x*y<0)
    cout<<abs(abs(y)-abs(x))+1<<endl;
}