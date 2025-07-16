#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define F first
#define S second
#define db double
#define pb push_back
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
using namespace std;
 
 ll mod=1e9 +7;
 
ll expo(ll base,ll exponent,ll mod){
    ll ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
 
vector<bool>  prime(90000002,true);
void Sieve() 
{ 
   
    for (int p=2; p*p<=90000001; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=90000001; i += p) 
                prime[i] = false; 
        } 
    } 
}

const ll M=200006;
ll f[M],inv[M];

void compute(){
    f[0]=1;
    rep(i,1,M-1){
        f[i]=(1LL*i*f[i-1])%mod;
    }
    inv[M-1]=expo(f[M-1],mod-2,mod);
    for(ll i=M-2;i>=0;i--){
        inv[i]=(1LL*(i+1)*inv[i+1])%mod;
    }
}
ll C(ll n,ll r){
    return (1LL*((1LL*f[n]*inv[r])%mod)*inv[n-r])%mod;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // compute();
    // Sieve();
    ll tests=1;
    // cin>>tests;
    while(tests--)
    {
      ll i,j,k,n;
      string s;
      cin>>n;
      cin>>s;
      // cout<<s<<"\n";
      vector<ll>r(n+1,0),g(n+1,0),b(n+1,0);
      for(i=n-1;i>=0;i--)
      {
        r[i]+=r[i+1];
        g[i]+=g[i+1];
        b[i]+=b[i+1];
        if(s[i]=='R') r[i]++;
        else if(s[i]=='G') g[i]++;
        else b[i]++;
      }
      // cout<<g[0]<<"\n";
      ll ans=0;
      rep(i,0,n-1)
      {
        rep(j,i+1,n-1)
        {
          if(s[i]==s[j]) continue;
          if((s[i]=='R' && s[j]=='G') || (s[i]=='G' && s[j]=='R'))
          {
            ans+=b[j+1];
            if(j+(j-i)<n && s[j+(j-i)]=='B') ans--;
          }
          else if((s[i]=='R' && s[j]=='B') || (s[i]=='B' && s[j]=='R'))
          {
            ans+=g[j+1];
            if(j+(j-i)<n && s[j+(j-i)]=='G') ans--;
          }
          else
          {
            ans+=r[j+1];
            if(j+(j-i)<n && s[j+(j-i)]=='R') ans--;
          }
        }
        // cout<<"--"<<ans<<"\n";
      }
      cout<<ans;

    }
    return 0;
   }