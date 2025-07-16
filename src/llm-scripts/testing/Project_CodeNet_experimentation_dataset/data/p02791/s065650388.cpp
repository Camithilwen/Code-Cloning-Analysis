                                              //BISMILLAHIR RAHMANIR RAHIM
                                               //BY THE NAME OF ALLAH
                                               //FAISAL AHAMMED SHAWON
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<utility>
#include<set>
#include<map>
#include<iterator>
#include<numeric>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define SQ(a) (a)*(a)
#define pi acos(-1.0)
const int MAX=100001;
const int MOD=1e9+7;
int ara[MAX];
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
void fast()
{
ios::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
}
ll gcd(ll a,ll b)
{
    if(b==0)
    return a;
    else
    gcd(b,a%b);
}
ll lcd(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}

bool f(ll a,ll b)
{
    return a>b;
}
ll max_sum_subarrays(ll ara[],ll n)
{
    ll ans=0,sum=0;
    for(ll k=0;k<n;k++){
        sum=max(ara[k],sum+ara[k]);
        ans=max(ans,sum);
    }
    return ans;
}
ll num_divisors(ll n)
{
    long long cnt=0;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0 && i*i==n)
            cnt+=1;
        if(n%i==0 && i*i!=n)
                cnt+=2;
    }
    return cnt;
}
ll comb(ll m, ll n)
{
    ll x = max(m-n,n),ans = 1,i=1;
    for(ll k=m;k>=x+1;k--){
        ans*=k;
        ans/=i;
        i++;
    }
    return ans;
}
ll binsearch(ll low,ll high,ll target)
{
    while(low<=high)
    {
        ll mid=(low+high)/2;
        if(ara[mid]>target)
            high=mid-1;
        else if(ara[mid]<target)
            low=mid+1;
        else return mid;
    }
    return -1;
}

int main()
{
    fast();
    int n;
    cin>>n;
    int ara[n];
    for(int i=0;i<n;i++)
    {
        cin>>ara[i];
    }
    int maxm=ara[0];
    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(maxm>ara[i])
        {
            maxm=ara[i];
            ans++;
        }
    }
    cout<<ans+1<<endl;
}