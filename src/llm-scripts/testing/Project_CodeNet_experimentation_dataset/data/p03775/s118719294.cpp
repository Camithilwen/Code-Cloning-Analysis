#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t m,j,l,q=0;
  cin>>m;
  for(j=1;j*j<=m;j++){
    if(m%j==0) l=m/j;
  }
  while(l>0){
    q++;
    l/=10;
  }
  cout<<q<<endl;
}