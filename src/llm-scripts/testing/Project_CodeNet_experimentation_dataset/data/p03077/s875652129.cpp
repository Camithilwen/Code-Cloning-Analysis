#include<bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main(){
  vector<ll>a(6);
  for(int i=0;i<6;i++){
    cin>>a.at(i);
  }
  ll min=a.at(0);
  for(int i=1;i<6;i++){
    if(a.at(i)<a.at(i-1)&&min>a.at(i)){
      min=a.at(i);
    }
  }
  ll ans=(a.at(0)-min)/min+5;
  if((a.at(0)-min)%min!=0)ans++;
  cout <<ans<<endl;
}