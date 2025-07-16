#include <bits/stdc++.h>
#define max 1000007
#define ll long long int
using namespace std;
vector <ll> primes;
void sieve()
{
    bool isprime[max+1];
    for(ll i=0;i<=max;i++) {
        isprime[i] = true;
    }
    isprime[0]=false;
    isprime[1]=false;
    for(ll i=3;i*i<=(max);i=i+2)
    {
        if(isprime[i]) {
            for (ll j = i*i; j  <= max; j=j+i) {
                isprime[j] = false;
            }
        }
    }
    primes.push_back(2);
    for(ll i=3;i<max;i=i+2)
    {
        if(isprime[i])
            primes.push_back(i);
    }
}
int main() {
    sieve();
    ll n,d,b,i,flag,x;
   scanf("%lld %lld",&d,&b);
    n=__gcd(d%b,b);
    set <int> s;
    s.insert(1);
    for(i=0;primes[i]*primes[i]<=n;i++)
    {
        while(n%primes[i]==0)
        {
            s.insert(primes[i]);
            n=n/primes[i];
        }
    }
    if(n>1)
        s.insert(n);
    printf("%lu",s.size());
    return 0;
}