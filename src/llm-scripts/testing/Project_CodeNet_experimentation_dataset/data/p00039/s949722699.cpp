#include<iostream>
#include<string>
using namespace std;
int main(){
long i,l,m,n,y;
string s;
while(cin>>s){
l=s.size();
y=0;m=1001;
for(i=0;i<l;i++){
if(s[i]=='I')n=1;
else if(s[i]=='V')n=5;
else if(s[i]=='X')n=10;
else if(s[i]=='L')n=50;
else if(s[i]=='C')n=100;
else if(s[i]=='D')n=500;
else if(s[i]=='M')n=1000;
if(m<n)y-=m*2;
y+=n;
m=n;
}
cout<<y<<endl;
}
return 0;
}