#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll mod = 1000000007;

ll fact[200010];


ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;
  
    x = x % p;
  
    while (y > 0) 
    {
        if (y & 1) 
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p; 
    } 
    return res; 
}


ll modInverse(ll n, ll p) 
{ 
    return power(n, p-2, p); 
}

void init(){

    fact[0] = 1;

	for(int i=1;i<=200005; i++){
		fact[i] = (fact[i-1]*i)%mod;
	}
}

ll sol(ll r, ll d){
    ll ans = fact[r+d];
    ans = (ans*modInverse(fact[r],mod))%mod;
    ans = (ans*modInverse(fact[d],mod))%mod;
    
    return ans;
}

int main() {
    init();
    int h,w,a,b;
    cin>>h>>w>>a>>b;
    
    ll ans = 0;
    ll t;
    
    for(int i=0; i<h-a; i++){
        t = 1;
        t = (t*sol(i,b-1))%mod;
        t = (t*sol(w-b-1,h-i-1))%mod;
        // cout<<i<<":"<<b<<" "<<w-b-1<<":"<<h-i-1<<'\n';
        ans = (ans + t)%mod;
    }
    
    cout<<ans;
    
    return 0;
}





