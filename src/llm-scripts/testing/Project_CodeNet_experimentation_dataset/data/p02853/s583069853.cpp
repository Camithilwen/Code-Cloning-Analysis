#include<bits/stdc++.h>
#define ll long long int 
using namespace std; 
int main(){
  ll x,y,sum=0;
  cin>>x>>y;
  if(x==1)sum+=300000;
  if(x==2)sum+=200000;
  if(x==3)sum+=100000;
  if(y==1)sum+=300000;
  if(y==2)sum+=200000;
  if(y==3)sum+=100000;
  if(x==1&&y==1)sum+=400000;
  cout<<sum<<endl;
  }