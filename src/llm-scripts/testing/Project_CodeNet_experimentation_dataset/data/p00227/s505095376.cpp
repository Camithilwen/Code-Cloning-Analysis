#include<bits/stdc++.h>
using namespace std;
int main(){
while(1){
  int n,m;
  int p[10000];
  int sum=0;
  cin>>n>>m;
  if(n==0 && m==0) break;
  for(int i=0;i<n;i++){
    cin>>p[i];
    }
  for(int i=0;i<n;i++){
    for(int j=0;j<n-1;j++){
      if(p[j]<p[j+1]) swap(p[j],p[j+1]);
      }
    }
  for(int i=0;i<n;i++){
    if(i%m==m-1) p[i]=0;
    }
  for(int i=0;i<n;i++){
    sum+=p[i];
    }
  cout<<sum<<endl;
}

  return 0;
}
