#include <bits/stdc++.h>
using namespace std;
signed main()
{
  int a,b,c=1,d;
  cin>>a>>b;
  d=a;
  for(int i=1;i<=d;i++){
    if(a>b){
    a-=b;
    a+=b-1;
    c++;
    }
  }
  cout<<c<<"\n";
}
