#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll n,num[3];
  cin>>n;
  for(int i=0;i<n;i++) cin>>num[i];
  if(n==2) num[2]=num[1];
  ll d=__gcd(num[0],num[1]);
  d=__gcd(d,num[2]);

  for(int i=1;i<=d;i++)if(d%i==0) cout <<i<<endl;  

  return 0;
}