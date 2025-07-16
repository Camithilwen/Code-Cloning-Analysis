#include<vector>
#include<list>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
  int h,i;
  int a[10],b[10];
  for(i=0;i<10;i++)
    cin>>a[i];
  for(i=0;i<10;i++)
    cin>>b[i];
  do{
    h=0;
    for(i=1;i<10;i++){
      if(a[i-1]<a[i]){
	swap(a[i-1],a[i]);
	h=1;
      }
    }
  }while(h);
  do{
    h=0;
    for(i=1;i<10;i++){
      if(b[i-1]<b[i]){
	swap(b[i-1],b[i]);
	h=1;
      }
    }
  }while(h);
  cout<<a[0]+a[1]+a[2]<<" "<<b[0]+b[1]+b[2]<<endl;
  return 0;
}