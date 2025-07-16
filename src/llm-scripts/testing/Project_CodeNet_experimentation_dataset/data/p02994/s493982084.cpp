#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
  int N,L;
  cin>>N>>L;
  int data[N];
  int m=1000,sum=0;
  rep(i,N){
      data[i]=L+i;
      m=min(m,abs(data[i]));
      sum+=data[i];
  }
  bool exist=false;
  rep(i,N){
      if(m==data[i]){
          exist=true;
          break;
      }
  }
  int ans;
  if(exist==true){
      ans=sum-m;
  }
  else{
      ans=sum+m;
  }
  
  cout<<ans<<endl;
}