#include<bits/stdc++.h>
using namespace std;
 

#define     fast()              ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define     ll                  long long int
#define     test()              ll t; cin>>t; while(t--) 
#define     lp0(i,begin,end)    for(ll i=begin;i<end;i++)
#define     lp1(i,begin,end)    for(ll i=begin;i<=end;i++)
#define     rlp(i,begin,end)    for(ll i=end;i>=begin;i--)
#define     prec(n)             fixed<<setprecision(n)
#define     initial(a,i)        memset(a,i,sizeof(a))
#define     pb                  push_back
#define     PI                  3.1415926535897932384626433832795
#define     MOD                 1000000007
#define     F                   first
#define     S                   second
#define     all(a)              (a).begin(),(a).end()
#define     BPC(x)              __builtin_popcountll(x)
#define     gcd(a,b)            __gcd(a,b)

ll gcd(ll a,ll b) {if (a==0) return b;return gcd(b%a,a);}

ll power(ll x,ll n)
{
    ll result = 1;
    while (n)
    {
        if (n & 1)
            result = result * x;
        n = n / 2;
        x = x * x;
    }
    return result;
}
// Solution Function
void solution(ll compte)
{
    // cout<<compte<<"\n";
    ll n,d;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    ll cnt =0;
    for(ll i=0;i<n;i++)
    {
        for(ll j=i+1;j<n;j++)
        {
            for(ll k=j+1;k<n;k++)
            {
                if(arr[i]!=arr[j]&&arr[j]!=arr[k]&&arr[k]!=arr[i]&&arr[i]+arr[j]>arr[k]&&arr[j]+arr[k]>arr[i]&&arr[k]+arr[i]>arr[j])
					cnt++;
            }
        }
    }
    cout<<cnt<<'\n';
}

// Driver Function
int main()
{
    ll compte = 1;
   // test()
    //{
        solution(compte);
        compte++;
    //}
    return 0;
}
