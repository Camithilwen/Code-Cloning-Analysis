#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int arr[200005];
int cache[200005][3];
int vis[200005][3];
int n;
int dp(int pos,int skip)
{
    if(skip>n%2+1)
        return -1e18;
    if(pos>=n)
    {
        if(!skip && n%2)
            return -1e18;
        return 0;
    }
    if(vis[pos][skip])
        return cache[pos][skip];
    vis[pos][skip]=1;
    int ans=max(dp(pos+1,skip+1),arr[pos]+dp(pos+2,skip));
    cache[pos][skip]=ans;
    return ans;
}
int32_t main() 
{
    IOS;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    print(dp(0,0));
}   
