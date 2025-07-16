#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int n,a[N];
void Put(int p) {p&1?puts("First"):puts("Second");exit(0);}
void dfs(int p)
{
    int od=0,ov=0,g=0,mn=1e9;
    for(int i=1;i<=n;i++) a[i]&1?od++:ov++,mn=min(mn,a[i]);
    if(ov&1) Put(p);
    if(od>1||mn==1) Put(p^1);
    for(int i=1;i<=n;g=__gcd(g,a[i]),i++) if(a[i]&1) a[i]--;
    for(int i=1;i<=n;i++) a[i]/=g;
    dfs(p^1);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1) Put(a[1]-1);dfs(1);
}
