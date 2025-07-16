#include<bits/stdc++.h>
#define N 10
using namespace std;

int main(){
  int a[N],b[N],ansa,ansb;
  for(int i=0;i<N;i++)cin>>a[i];
  for(int i=0;i<N;i++)cin>>b[i];
  sort(a,a+N,greater<int>());
  sort(b,b+N,greater<int>());
  ansa=ansb=0;
  for(int i=0;i<3;i++)ansa+=a[i];
  for(int i=0;i<3;i++)ansb+=b[i];
  cout<<ansa<<' '<<ansb<<endl;
  return 0;
}