#include <iostream>
#include <string>
using namespace std;
int main(){
string a;
cin >> a;
int b;
b=a.size();
int c;
c=0;
int e[b];
while(c<b){
string d(a,c,1);
if(d=="J"){e[c]=1;}
if(d=="O"){e[c]=2;}
if(d=="I"){e[c]=3;}
c=c+1;}
int f;
f=0;
int g;
g=0;
int  h;
int i;
c=0;
while(c<b){
h=0;
i=0;
if(e[c]==2){f=f+1;}
if(e[c]==3){if(f>g){if(c>2*f-1){if(c<b-f+1){while(h<f){if(e[c-f-1-h]!=1){i=1;} if(e[c+h]!=3){i=1;} h=h+1;} if(i==0){g=f;} f=0;}}}}
if(e[c]==1){f=0;}
c=c+1;
}
cout << g<<endl;
}