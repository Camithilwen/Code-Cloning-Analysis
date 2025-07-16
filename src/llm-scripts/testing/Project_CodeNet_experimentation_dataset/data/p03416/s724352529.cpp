#include <bits/stdc++.h>
using namespace std;
int main (){
  int a,b,d,e,A,B,N;
  cin>>A>>B;
  N=0;
  for(int i=A;i<B+1;i++){
    a=i%10;
    b=(i/10)%10;
    d=(i/1000)%10;
    e=(i/10000)%10;
    if(a==e&&b==d){
    N++;
    } 
  }
  cout<<N<<endl;
}
