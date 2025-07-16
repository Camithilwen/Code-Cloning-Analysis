#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

vector<ll> prime(ll n){
    vector<ll> rt;
    for(ll i=2;i*i<n;i++){
        ll tmp=0;
        while(n%i==0){
            tmp++;
            n/=i;
        }
        if(n%i!=0&&tmp!=0) rt.push_back(tmp);
    }
    if(n!=1) rt.push_back(1);
    return rt;
}

int main(){
    ll a,b;
    cin>>a>>b;
    if(a>b) swap(a,b);
    ll g=gcd(a,b);
    vector<ll> com=prime(g);
    // ll ans=1;
    // for(ll x:com){
    //     //cout<<x<<endl;
    //     ans*=(x+1);
    // }
    cout<<com.size()+1<<endl;
}