#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll N;
string s;
int main(){
  cin>>N>>s;bool y=false;vector<ll>a(N);
  for(ll I=0;I<2;I++){
    for(ll J=0;J<2;J++){
  a[0]=I;a[1]=J;
    for(ll i=1;i<N-1;i++)
      if((a[i]==1 && s[i]=='o')||(a[i]==0 && s[i]=='x')){
      a[i+1]=1-a[i-1];
      }else
        a[i+1]=a[i-1];
      bool x=true;
 if((a[N-1]==1 && s[N-1]=='o')||(a[N-1]==0 && s[N-1]=='x')){
      if(a[N-2]==a[0])x=false;
      }else{
  if(a[N-2]!=a[0])x=false;
 }
      if((a[0]==1 && s[0]=='o')||(a[0]==0 && s[0]=='x')){
      if(a[N-1]==a[1])x=false;
      }else{
  if(a[N-1]!=a[1])x=false;
 }if(x==true){y=true;break;}
        
    }if(y)break;
  }if(!y)
      cout<<-1<<endl;
  else{
  string S="";
    for(ll i=0;i<N;i++)
      if(a[i]==0)
        S+='S';
    else
      S+='W';
  cout<<S<<endl;
  }
  return 0;
}