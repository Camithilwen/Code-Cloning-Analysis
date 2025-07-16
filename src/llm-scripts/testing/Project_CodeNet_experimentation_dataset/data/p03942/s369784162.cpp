#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1000010;
int x,n,fl,ans;
char s[maxn],t[maxn];
queue<int>q;
signed main()
{
    cin>>n>>s+1>>t+1;
    for(int i=1;i<=n;i++)if(s[i]!=t[i]){fl=1;continue;}
    if(!fl)puts("0"),exit(0);
    int x=n,y=n;
    while(y)
    {
        while(y>1&&t[y]==t[y-1])y--;
        while(x>0&&(x>y||s[x]!=t[y]))x--;
        if(x<=0)puts("-1"),exit(0);
        while (!q.empty()&&q.front()-q.size()>=y)q.pop();
        if(x!=y)q.push(x);
        ans=max(ans,(int)q.size()+1);
        y--;
    }
    cout<<ans;
}