#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void read(int &x)
{
    int f=1;
    x=0;
    char s=getchar();
    while(s<'0'||s>'9')
    {
        if(s=='-')
            f=-1;
        s=getchar();
    }
    while(s>='0'&&s<='9')
    {
        x=x*10+s-'0';
        s=getchar();
    }
    x*=f;
}
#define N 100005
int n,m,t;
int a[N],b[N];
int main(){
    cin>>n>>m>>t;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin>>b[i];
    }
    int ans=1e9;
    for (int i = 0; i < t; i++)
    {
        int x,y,c;
        cin>>x>>y>>c;
        ans= min(a[x]+b[y]-c,ans);
    }
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    cout<<min(ans,a[1]+b[1]);
    
    
    return 0;
}