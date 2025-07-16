

//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cstdlib>
#include<bitset>
#include<sstream>
#include<queue>
#include<stack>
#include<list>
#include<limits>
#include<iomanip>

using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pt;
typedef pair<ll,ll> pll;

#define Max 1000001
#define intinf 2147483647
#define longlonginf 9223372036854775807
#define MOD 998244353
#define MOD2 1000000007
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vint vector<int>
#define vll vector<long long>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define F(i,n) for(int i = 0;i<n;i++)
#define Fr(i,l,r) for(int i = l;i <= r;i++)
#define rF(i,n) for(int i = n-1;i>=0;i--)


//#define min(a,b) a>b?b:a
//#define max(a,b) a>b?a:b
#define all(arr) arr.begin(),arr.end()
//#define sort(vec) sort(vec.begin(),vec.end())
//#define reverse(vec) reverse(vec.begin(),vec.end())

const ll m = 1e9 + 9;


ll Lpow(ll a,ll b)
{
    ll ans = 1;
    while(b > 0)
    {
        if(b%2)
            ans = (ans*a)%m;
        a = (a*a)%m;
        b = b/2;
    }
    return ans;
}

ll gcd(ll a,ll b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}


signed main()
{
    fastio;
    
    int h1,m1,h2,m2,k;
    
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    
    int ans = (h2-h1)*60 + m2 - m1;
    
    if(ans <= 0)
        ans += 24*60;
    
    ans = max(ans-k,0);
    
    cout << ans << endl;
   
    return 0;
}
