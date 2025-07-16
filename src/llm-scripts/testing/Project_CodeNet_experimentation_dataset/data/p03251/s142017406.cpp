#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); i++)

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);


ll gcd(ll a, ll b){  if(b==0){  return a; }   return gcd(b , a%b); }


int main() {


int n,m,x,y;
cin>>n>>m>>x>>y;
int a[n],b[m];
REP(i,n){
  cin>>a[i];
}
REP(i,m){
  cin>>b[i];
}

int max_a = INT_MIN;
int min_b = INT_MAX;

REP(i,n){
  max_a = max(max_a,a[i]);
}
REP(i,m){
  min_b = min(min_b,b[i]);
}

int ans;
int flag = 0;

for(int i=x+1;i<y;i++){
  if( i > max_a && i<=min_b){
    flag = 1;
    ans = i;
    break;
  }
}

if(flag){
 cout<<"No War\n";
}
else{
  cout<<"War\n";
}


  
  return 0;
}
