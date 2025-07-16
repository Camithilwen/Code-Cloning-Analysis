#include<bits/stdc++.h>
using namespace std;
int main(){
  int A,B;
  cin>>A>>B;
   //if(B<=A) cout<<0<<endl;
  if(B==1) cout<<0<<endl;
  else if(A==B) cout<<1<<endl;
  else if((B-A)%(A-1)==0) cout<<(B-1)/(A-1)<<endl;
  else cout<<1+(B-1)/(A-1)<<endl;
}