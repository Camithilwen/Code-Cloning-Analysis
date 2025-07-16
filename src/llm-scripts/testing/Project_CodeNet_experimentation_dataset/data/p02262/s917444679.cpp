#include <iostream>
using namespace std;
int main(void){
  int cnt=0,m=0,n,a[1000000],g[100]={0};
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>a[i];
  g[0]=1;
  while(g[m]<n){
    g[m+1]=3*g[m]+1;
    m++;
  }
  if(n==1)
    m=1;
  for(int i=m-1;i>=0;i--){
    for(int k=g[i];k<n;k++){
      int v=a[k];
      int j=k-g[i];
      while(j>=0&&a[j]>v){
	a[j+g[i]]=a[j];
	j=j-g[i];
	cnt++;
      }
      a[j+g[i]]=v;
    }
  }
  cout<<m<<endl;
  for(int i=m-1;i>0;i--)
    cout<<g[i]<<" ";
  cout<<g[0]<<endl;
  cout<<cnt<<endl;
  for(int i=0;i<n;i++)
    cout<<a[i]<<endl;
  return 0;
}