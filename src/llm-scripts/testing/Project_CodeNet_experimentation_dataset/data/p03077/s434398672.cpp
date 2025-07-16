#include<bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main(){
  ll n,a,b,c,d,e,f,g;
  cin>>n>>a>>b>>c>>d>>e;
  f=min(min(min(min(a,b),c),d),e);
  g=n/f;
  if(n%f>0) g++;
  cout<<g+4<<endl;
}