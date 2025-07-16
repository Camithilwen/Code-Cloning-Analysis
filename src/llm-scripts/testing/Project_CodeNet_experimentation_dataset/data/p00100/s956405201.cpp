#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
  int n;
  while(cin>>n,n){
    unsigned long long a[5000]={0},c=0,p,o,u;
    rep(i,n){
      cin>>p>>o>>u;
      a[p]+=o*u;
      if(a[p]>=1000000){cout<<p<<endl;c++;}
    }
    if(!c)cout<<"NA"<<endl;
  }
}