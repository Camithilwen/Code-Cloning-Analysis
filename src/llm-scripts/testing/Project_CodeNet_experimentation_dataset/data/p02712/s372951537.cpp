#include <bits/stdc++.h>
#include<string>
#define mod 1000000007
using ll = long long;
using namespace std; 

int main(){
    ll n; cin >> n;
    ll ans=0;
    ll s=n/3;
    ll a=n/5;
    ll d=n/15;
    ans=(1+n)*n/2;
    ans=ans-(3+s*3)*s/2-(5+a*5)*a/2+(15+d*15)*d/2; 
    cout << ans << "\n";
}

