#include<bits/stdc++.h>
using namespace std;
typedef int64_t ll;

int main(){
  ll n;
  cin>>n;
  ll a[n],b[n];
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++)cin>>b[i];
  reverse(b,b+n);
  ll j=0;
  for(int i=0;i<n;i++){
    if(a[i]==b[i]){
      for(;j<n;j++){
        if(a[i]!=b[j] && a[j]!=b[i]){
          swap(b[i],b[j]);
          break;
        }
      }
      if(a[i]==b[i]){cout<<"No"<<endl;return 0;}
    }
  }
  cout<<"Yes"<<endl;
  for(int i=0;i<n;i++)cout<<b[i]<<" ";
  cout<<endl;
}
