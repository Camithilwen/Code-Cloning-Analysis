#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define pb push_back
#define vl vector
#define ff first
#define ss second
using namespace std;
int main()
{
    ll a,b,i,j,n,t,c,m;
    cin>>n>>m;
    ll l,r;
    ll arr[n+1]={0};
    for(i=0;i<m;i++)
    {
        cin>>l>>r;
        l--;
        arr[l]++;
        arr[r]--;
    }
    for(i=1;i<n+1;i++) arr[i]+=arr[i-1];
    ll count=0;
    for(i=0;i<n+1;i++) if(arr[i]==m) count++;
    cout<<count;
}