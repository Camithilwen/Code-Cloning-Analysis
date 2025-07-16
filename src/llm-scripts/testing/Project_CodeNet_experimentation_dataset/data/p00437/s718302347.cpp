#include <iostream>
#include <string>
using namespace std;
int main(){
int a;
int b;
int c;
int h;
int n;
while(cin >>a>>b>>c){
if(a==0&&b==0&&c==0){break;}
cin >>n;
int d[n];
int e[n];
int f[n];
int g[n];
int i[a+b+c];
h=0;
while(h<n){
cin >>d[h];
cin >>e[h];
cin >>f[h];
cin >>g[h];
h=h+1;}
h=0;
while(h<a+b+c){
i[h]=2;
h=h+1;}
h=0;
while(h<n){
if(g[h]==1){i[d[h]-1]=1; i[e[h]-1]=1; i[f[h]-1]=1;}
h=h+1;}
h=0;
while(h<n){
if(i[d[h]-1]==1&&i[e[h]-1]==1&&g[h]==0){i[f[h]-1]=0;}
if(i[f[h]-1]==1&&i[e[h]-1]==1&&g[h]==0){i[d[h]-1]=0;}
if(i[d[h]-1]==1&&i[f[h]-1]==1&&g[h]==0){i[e[h]-1]=0;}
h=h+1;}
h=0;
while(h<a+b+c){
cout <<i[h]<<endl;
h=h+1;}
}}