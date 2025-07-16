#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int ll
#define pb push_back
#define setbits(x)          __builtin_popcountll(x)
#define endl "\n"
typedef long long ll;
int fact(int n)
{
    if(n==0)
        return 1;
        int ans=1;
    for(int i=1;i<=n;i++)
     ans*=i;
     return ans;
}
int find(int n,int m)
{
  int r=fact(n)/(fact(n-m));
  return r;
}
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
int ans=1;
int arr[n];
for(int i=0;i<n;i++)
    cin>>arr[i];
    int mod=pow(10,9)+7;
    map<int,int> mp;
    mp[-1]=1;
for(int i=0;i<n;i++)
{
    int x=arr[i];
    int val=mp[x-1];
    ans*=val;
    ans%=mod;
    mp[x]+=1;
    if(x-1!=-1&&mp[x-1])
    mp[x-1]-=1;
}
int r=0;
for(int i=0;i<n;i++)
{
    if(arr[i]==0)
        r++;
}
if(r<=3)
ans*=find(3,r);
else
    ans=0;
ans%=mod;
cout<<ans<<endl;

    return 0;
}

