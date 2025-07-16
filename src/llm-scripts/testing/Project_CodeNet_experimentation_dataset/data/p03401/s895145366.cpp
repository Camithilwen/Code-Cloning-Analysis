#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
#define PI 3.14159265359
#define MOD 1000000007
const int MAX = 510000;
ll gcd(ll a, ll b){
    if (a % b == 0)
    {  return(b);}
    else{return(gcd(b, a % b));}
}
ll lcm(ll a, ll b)
{return a * b / gcd(a, b);}

int main(){
  int n;
  cin >>n;
  vector<int>a(n);
  vector<ll>x(n+1);
  rep(i,n){cin>>a[i];}
  x[0]=abs(a[0]-0ll);
  for(int i=1;i<n;i++){
  	x[i]=abs(a[i]-a[i-1]);
  }
  x[n]=abs(a[n-1]-0ll);
  ll sum=0;
  rep(i,n+1){sum+=x[i];}
  //i=0のとき
  cout<<sum-x[0]-x[1]+abs(a[1]-0ll)<<endl;
  for(int i=1;i<=n-2;i++){
  	cout<<sum-x[i]-x[i+1]+abs(a[i+1]-a[i-1])<<endl;
  }
  cout<<sum-x[n-1]-x[n]+abs(a[n-2]-0);
}