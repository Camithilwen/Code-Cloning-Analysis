//Tonight's the night and it is going to happen again and again.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define T ll t; cin>>t; while(t--)
#define mod 1000000007
#define inf 1000000000000000000
#define mem(name,val) memset(name,val,sizeof(name))
#define f(n) for(ll i=0;i<n;i++)
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define endl "\n"
ll gcd(ll a,ll b){if(b==0){return a;}return gcd(b,a%b);}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   #endif
   int n;ll sum=0;cin>>n;int a[n];
   f(n){cin>>a[i];}
   rep(i,1,n)
   {
    if(a[i]<a[i-1]){sum+=a[i-1]-a[i];a[i]=a[i-1];}
   }
   cout<<sum; 
}