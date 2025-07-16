#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 200011

int main(){
   ll n,i;


   cin>>n;
   ll a[n+9],b[n+9];


    for(i=1;i<=n;i++){
    cin>>a[i];
   }
  sort(a+1,a+1+n);
  ll s=0,p=0,q=0;
  for(i=n;i>1;i--){
    if(a[i]==a[i-1] && a[i]!=p){


        if(s==0) {
            p=a[i];
            s=1;
        }
        if(s==1 && a[i]!=p){
            q=a[i];
            break;
        }
    }
  }
  ll x=0;
   for(i=n;i>1;i--){
    if(a[i]==a[i-1] && a[i]==a[i-2]&& a[i]==a[i-3]){

       x=a[i];
       break;
    }
  }
  if(x==0 && p*q==0){
    cout<<0<<endl;
  }
 else if(p*q>x*x){
    cout<<p*q<<endl;
  }
  else cout<<x*x<<endl;

}

