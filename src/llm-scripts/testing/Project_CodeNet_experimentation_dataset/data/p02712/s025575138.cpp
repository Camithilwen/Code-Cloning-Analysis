#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,a,b,c;
    cin >> n;
    a=n/3;
    b=n/5;
    c=n/15;
  if(n%2==0){
    n=n/2*(n+1);
  }else{
    n=(n+1)/2*n;
  }
    a=a*(a+1)/2;
    b=b*(b+1)/2;
    c=c*(c+1)/2;
    cout << n-a*3-b*5+c*15;

}