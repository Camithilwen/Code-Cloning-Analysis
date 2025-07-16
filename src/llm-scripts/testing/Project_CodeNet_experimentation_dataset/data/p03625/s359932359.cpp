#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
  int n;
  cin>>n;
  map<int,int> m;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    m[a]++;
  }
  ll n1=0,n2=0;
  for(auto i:m){
    if(i.second>=4){
      n1=i.first,n2=i.first;
    }else if(i.second>=2){
      swap(n1,n2);
      n1=i.first;
    }
  }
  cout<<n1*n2<<endl;
  return 0;
}