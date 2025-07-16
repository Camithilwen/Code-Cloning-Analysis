#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll n,a,b;
  cin>>n;
  cout<<50<<endl;
  a=n/50;
  b=n%50;
  for(int i=0;i<b;i++){
    cout<<50+a-i<<" ";
  }
  for(int i=b;i<50;i++){
    cout<<max(0LL,49+a-i)<<" ";
  }
}