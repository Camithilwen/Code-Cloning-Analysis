#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,X,T;
  cin>>N>>X>>T;
  if(N%X==0) cout<<N/X*T;
  else cout<<(int(N/X)+1)*T<<endl;
}
