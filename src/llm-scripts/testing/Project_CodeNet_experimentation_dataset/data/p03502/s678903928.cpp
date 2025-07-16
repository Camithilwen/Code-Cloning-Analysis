#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,T;
  cin>>N;
  T=N;
  int sum=0;
  while(N>0){
    sum+=N%10;
    N/=10;
    }
  if (T%sum==0)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
  return 0;
}