#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vec(x) vector<x>
#define pb push_back
#define pii pair<ll,ll>
#define vi vector<ll>
#define vii vector<pair<ll,ll>>
#define matrix(x) vector<vector<x>>
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a, b, sizeof a)
#define ff first
#define ss second
#define mp make_pair
const int INF = 1e9;
const int MOD = 1e9 + 7;
int main()
{
ll t;
cin>>t;
ll a[t];
for(ll i=0;i<t;i++)
{
    cin>>a[i];
}
sort(a,a+t);
ll x=a[t-1];
ll cont=0;
ll s=0;
ll res=1;
for(ll i=t-1;i>=0;i--)
{

    if(x==a[i])
    {
        cont++;
    }
    else
    {
        cont=1;
        x=a[i];
    }
     if(cont==2)
    {
        s=s+1;
        cont=0;
        res=res*x;
        x=a[i-1];

    }
    if(s==2)
        break;

}
if(s>=2)
cout<<res<<endl;
else
    cout<<0<<endl;
}
