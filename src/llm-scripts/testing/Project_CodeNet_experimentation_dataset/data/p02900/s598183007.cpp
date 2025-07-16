#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool isprime(ll x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return true;
}

int main()
{
    vector<ll>common;
    ll a,b;
    cin>>a>>b;
    set<ll>f,g;
    bool ok=false;
    while (a % 2 == 0)
    {
        f.insert(2);
        a = a/2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(a); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (a % i == 0)
        {
            f.insert(i);
            a = a/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (a > 2)
        f.insert(a);

         while (b % 2 == 0)
    {
        g.insert(2);
        b = b/2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(b); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (b % i == 0)
        {
            g.insert(i);
            b = b/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (b > 2)
        g.insert(b);


      ll ans=0;
      for(auto x:g){
        if(f.count(x))ans++;
      }
      ans++;
      cout<<ans;

    return 0;

}
