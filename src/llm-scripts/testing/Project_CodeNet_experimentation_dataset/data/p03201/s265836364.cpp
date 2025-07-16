#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("sse4")
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define imx INT_MAX
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
typedef pair<int,int> pii;
int n,x,ans;
LL pow2[50];
map<int,int>mp;
priority_queue<int>pq;
int main()
{
    pow2[0]=1;
    for(int i=1;i<=31;i++)pow2[i]=pow2[i-1]*2;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        mp[x]++;
        pq.push(x);
    }
    while(!pq.empty())
    {
        if(mp[pq.top()]==0)
        {
            pq.pop();
            continue;
        }
        mp[pq.top()]--;
        for(int i=31;i>-1;i--)
        {
            if(pow2[i]-pq.top()>pq.top())continue;
            if(mp[pow2[i]-pq.top()]>0)
            {
                mp[pow2[i]-pq.top()]--;
                ans++;
                break;
            }
        }
        pq.pop();
    }
    printf("%d",ans);
}
