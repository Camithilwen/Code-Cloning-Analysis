#include<bits/stdc++.h>
using namespace std;
int main(){
  long long a,b,k;
  cin>>a>>b>>k;
  while(k){
    if(a%2==1)a--;
    a/=2;
    b+=a;
    k--;
    if(k==0)break;
    if(b%2==1)b--;
    b/=2;
    a+=b;
    k--;
    if(k==0)break;
  }
  cout<<a<<" "<<b<<endl;
  return 0;
}