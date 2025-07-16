#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,K;
  cin>>N>>K;
  if(N<K){
    cout<<1<<endl;
  }
  else if(N%K==0){
    cout<<0<<endl;
  }
  else{
    cout<<1<<endl;
  }
}
