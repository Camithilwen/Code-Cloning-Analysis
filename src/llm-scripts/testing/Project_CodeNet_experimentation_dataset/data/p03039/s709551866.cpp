#include <iostream>
#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll Mod = 1e9 + 7;
ll fact[200100];

long long fastpower(long long a,long long b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a;
    long long res = fastpower(a,b/2)%Mod;
    res = (res %Mod  * res % Mod )%Mod;
    if(b%2!=0)
        res*=a;
    return res % Mod;
}

ll C(ll n , ll k){

    if(n < k)  return 0;
    ll x = fact[n];
    ll y = (fact[k] * fact[n - k])%Mod;
    return ((x * fastpower(y , Mod - 2))%Mod);
}

void add_self(ll &x , ll y){
    x = (x + y)%Mod;
}

void sub_self(ll &x , ll y){
    x = ((x - y)%Mod)+Mod;
}

vector < ll > v , v2;

int main()
{
    ll n,m,k;  cin >> n >> m >> k;
    fact[0] = 1;
    for(int i = 1;i<=200000;i++)  fact[i] = (fact[i - 1] * i) % Mod;
    ll sum = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            v.push_back(i);
            v2.push_back(j);
        }
    }
    sort(v.begin() , v.end());
    sort(v2.begin() , v2.end());
    ll Ans = 0;
    for(ll i = 0;i<v.size();i++){
        ll Ways  = C(n * m - 2 , k - 2);
        sub_self(Ans , v[i] * ((ll)v.size() - (i + 1)) * Ways +  Mod);
        add_self(Ans , v[i] * i % Mod * Ways);
    }
    for(ll i = 0;i<v2.size();i++){
        ll Ways  = C(n * m - 2 , k - 2);
        sub_self(Ans , v2[i] * ((ll)v2.size() - (i + 1)) * Ways + Mod);
        add_self(Ans , v2[i] * i % Mod * Ways);
    }
    cout << Ans;
    return 0;
}
