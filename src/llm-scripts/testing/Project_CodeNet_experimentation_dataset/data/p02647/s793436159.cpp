#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define all(x) (x).begin(),(x).end()
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
using Graph = vector<vector<int>>;
const ll mod=1000000007;
const int MAX_N = 1000;         // n の最大値
 
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
ll n,p;
cin>>n>>p;
ll ca=0;
ll a[n+2]={};
ll b[n+2]={};
ll m=0;
ll f=0;
for(ll i=1; i<n+1; i++){
cin>>a[i];}
for(ll i=0; i<p; i++){
  
for(ll k=1; k<=n; k++){
if(k-a[k]<=0){
b[0]++;}
else{
b[k-a[k]]++;}
if(k+a[k]>=n){
b[n+1]--;}
else{
b[k+a[k]+1]--;}}
ca=b[0];
b[0]=0;
for(ll k=1; k<=n; k++){
ca+=b[k];
b[k]=0;
a[k]=ca;
if(a[k]==n){
m++;}
}
if(m==n) {f++; break;}
m=0;
ca=0;}
for(ll i=1; i<=n; i++){
cout << a[i] << " ";}
cout << endl;}
