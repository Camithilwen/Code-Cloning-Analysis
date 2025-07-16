#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod=1000000007;
const int MAX_N = 1000;         // n の最大値
 
// nCk を取得
double nCk(int n, int k) {
double res=1.0;
for(int i=0; i<n; i++){
res*=0.5;}
for(int i=0; i<k; i++){
res*=(double)(n-i);
res/=(double)(k-i);
}
return res;}
 
int main() {
ll h,w,n;
cin>>h>>w>>n;
ll ans=0;
if(h>w){
if(n%h==0){
ans = n/h;}
else{
ans = n/h +1;}}
else{
if(n%w==0){
ans = n/w;}
else{
ans = n/w +1;}}
cout << ans << endl;}
