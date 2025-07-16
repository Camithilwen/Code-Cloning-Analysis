#include<iostream>
#include<string>
using namespace std;

int main(){
char x[200];
char Roma[7]={'I','V','X','L','C','D','M'};
int Arabia[7]={1,5,10,50,100,500,1000};
int a=0,b,ans=0,ls;
string s;
while(cin>>s){
ans=0;
a=0;
ls=s.size();
for(int i=ls-1;i>-1;i--){
for(int j=0;j<7;j++){
if(s[i]==Roma[j])b=Arabia[j];}
if(b>=a){ans+=b; a=b;}
if(b<a)ans-=b;}
cout<<ans<<endl;}}