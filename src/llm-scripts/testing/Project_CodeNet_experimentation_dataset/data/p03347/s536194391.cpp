#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=1000000007;
const long double PI=3.1415926535;

int main() {
  ll N;
  cin>>N;
  ll a[N];
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  ll ans=0,cnt=0,c=1;
  if(a[0]!=0){
    c=0;
  }
  for(int i=0;i<N;i++){
    if(i==N-1){
      ans+=a[i];
    }
    else if(a[i]+1==a[i+1]){
      cnt++;
    }
    else if(a[i]+1<a[i+1]){
      c=0;
      break;
    }
    else{
      ans+=a[i];
    }
  }
  if(c){
    cout<<ans;
  }
  else{
    cout<<-1;
  }
}