#include<iostream>
using namespace std;

int main(){
  int n,m;
  while(1){
  int  ans=0,p[10001]={};
  cin>>n>>m;
  if(n+m==0)break;
  for(int i=1;i<=n;i++){
    cin>>p[i];
  }

  for(int j=0;j<n;j++)
    for(int i=1;i<=n;i++)
      if(p[i]<p[i+1])swap(p[i],p[i+1]);


  for(int i=1;i<=n;i++){
    if(i%m==0)p[i]=0;
    ans+=p[i];
  }


  cout<<ans<<endl;
  }
  return 0;
}