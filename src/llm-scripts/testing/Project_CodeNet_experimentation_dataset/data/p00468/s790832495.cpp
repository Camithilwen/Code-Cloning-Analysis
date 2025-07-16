#include <iostream>
#include <string>
using namespace std;
int main(){
int n;
int m;
int c;
int e;
while(cin >>n>>m){
if(n==0&&m==0){break;}
int a[m];
int b[m];
c=0;
while(c<m){
cin >>a[c]>>b[c];
c=c+1;}
int d[n];
d[0]=3;
c=1;
while(c<n){
d[c]=0;
c=c+1;}
c=0;
while(c<m){
if(a[c]==1){d[b[c]-1]=2;}
if(b[c]==1){d[a[c]-1]=2;}
c=c+1;}
c=0;
while(c<m){
if(d[a[c]-1]==2&&d[b[c]-1]==0){d[b[c]-1]=1;}
if(d[b[c]-1]==2&&d[a[c]-1]==0){d[a[c]-1]=1;}
c=c+1;}
e=0;
c=1;
while(c<n){
if(d[c]==1||d[c]==2){e=e+1;}
c=c+1;}
cout <<e<<endl;}}