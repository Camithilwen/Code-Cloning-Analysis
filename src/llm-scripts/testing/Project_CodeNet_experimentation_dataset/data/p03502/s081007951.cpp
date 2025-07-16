#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,t;
  
  cin >> N;
  t=N;
  
  int f=0;
  
  for(int i=0;i<9;i++){
    f = f+ (t%10);
    t=t/10;
  }
  
  if(N%f==0)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  
}