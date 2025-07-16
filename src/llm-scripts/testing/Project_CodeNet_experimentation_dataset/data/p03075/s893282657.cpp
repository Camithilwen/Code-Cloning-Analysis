#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a[10];
  int k,b;
  for(int i=0;i<5;i++){
    cin>>a[i];
  }
  cin>>k;
  sort(a,a+5);
  b=a[4]-a[0];
  if(k<b){
    cout<<":("<<"\n";
  }
  else{
    cout<<"Yay!"<<"\n";
  }
  return 0;
}