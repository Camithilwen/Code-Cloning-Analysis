#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll n;
  cin>>n;
  ll mi=ll(1e18);
  for(int i=0;i<5;i++){
    ll a;
    cin>>a;
    mi=min(mi,a);
  }
  ll x=n/mi;
  if(n%mi==0) x--;
  cout<<5+x<<endl;
}