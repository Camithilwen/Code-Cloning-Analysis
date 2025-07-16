#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  if((a-b == 0)+(a-c == 0)+(b-c == 0)==1){
   cout<<"Yes"<<endl;
  }else{
   cout<<"No"<<endl;
  }
}