#include<bits/stdc++.h>
using namespace std;
int main(){
  int P,Q,R,a,b,c,d;
  cin>>P>>Q>>R;
  a=P+Q;
  b=Q+R;
  c=R+P;
  d=min({a,b,c});
  cout<<d<<endl;
}