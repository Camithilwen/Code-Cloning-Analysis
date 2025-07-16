#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll rm[2000005]={0},rc[2000005]={0},rmc[2000005]={0};
ll n;
string s;
ll solve(ll k){
  ll res=0;
  for(int i=1;i<=n;i++){
    if(s[i]=='D'){
      res+=rmc[i+k-1]-rmc[i];
      res-=rm[i]*(rc[i+k-1]-rc[i]);
    }
  }
  return res;
}
int main(){
  cin>>n;
  s.push_back('A');
  string ks;
  cin>>ks;
  s+=ks;

  for(int i=1;i<=n;i++){
    rm[i]=rm[i-1];
    rc[i]=rc[i-1];
    rmc[i]=rmc[i-1];
    if(s[i]=='M') rm[i]++;
    if(s[i]=='C') {
      rc[i]++;
      rmc[i]+=rm[i];
    }
  }
  for(int i=n+1;i<=n*2;i++){
    rm[i]=rm[i-1];
    rc[i]=rc[i-1];
    rmc[i]=rmc[i-1];
  }
  ll q;
  cin>>q;
  for(int i=0;i<q;i++){
    ll k;
    cin>>k;
    cout<<solve(k)<<endl;
  }
}
