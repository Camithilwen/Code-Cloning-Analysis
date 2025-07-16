#include <bits/stdc++.h>
using namespace std;

long long a,b,x,y,k
;


int main(){
  cin>>a>>b;
  for(long long i=a;i<=b;i++){
   if(i%10==i/10000){
        x=i/10;
        y=i/1000;
    if((x%10)==(y%10))k++;
   }
  }
  cout<<k;
    return 0;
}
