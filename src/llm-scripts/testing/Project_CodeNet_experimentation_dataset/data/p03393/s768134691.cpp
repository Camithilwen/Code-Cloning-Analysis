#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod=1000000007;
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int main() {
string s;
cin>>s;
int a=0;
int b=0;
int n=s.size();
int c[n]={};
char w;
int p=0;
if(n!=26){
for(int i=0; i<n; i++){
c[i]=s.at(i)-'a'+1;}
sort(c,c+n);
for(int i=0; i<n; i++){
if(c[i]!=i+1){
a=i;
p++;
break;
}}
if(p==0){
a=n;}
char q=a+'a';
s+=q;
cout<<s<<endl;}
else{
for(int i=0; i<n; i++){
c[i]=s.at(i)-'a';}
for(int i=0; i<n; i++){
if(c[n-2-i]<c[n-1-i]){
a=n-1-i;
b=1;
break;}}
if(b!=1){
cout<<-1<<endl;}
else{
b=10000;
for(int k=a; k<n; k++){
if(c[a-1]<c[k]){
b=min(b,c[k]);}
}
w=b+'a';
for(int i=0; i<a-1; i++){
cout<<s.at(i);}
cout<<w<<endl;}}}
