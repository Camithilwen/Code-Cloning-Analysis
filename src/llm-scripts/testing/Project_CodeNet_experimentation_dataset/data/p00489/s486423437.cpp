#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int a,b,c,d;
  int pnt[1000]={};

  for(int i=0;i<(n*(n-1)/2);i++){
cin>>a>>b>>c>>d;
 if(c>d) pnt[a]+=3;
 else if(d>c)pnt[b]+=3;
 else if(d==c) pnt[a]++,pnt[b]++;
  }
  int vic[1000];

  for(int i=1;i<=n;i++){
    int cnt=1;
    for(int j=1;j<=n;j++)if(pnt[i]<pnt[j])cnt++;
    vic[i]=cnt;
  }
  for(int i=1;i<=n;i++) cout<<vic[i]<<endl;


  return 0;
}