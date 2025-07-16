#include<bits/stdc++.h>
using namespace std;
#define N 1001000
#define inf INT_MAX
inline int read()
{
    int s=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
    return s*w;
}
int n;
char a[N],b[N];
int pos[N],Ans,cnt,ans[N];
bool Chtholly=true;
int main()
{
    //freopen("game.in","r",stdin);
    //freopen("game.out","w",stdout);
    n=read();
    scanf("%s%s",a+1,b+1);
    int len=1;
    //while(a[len]==b[len])
    //for(int i=1;i<=n+10;i++) cout<<a[i]<<endl;
    while(a[len]==b[len]&&len<=n) len++;
    if(len==n+1) return puts("0"),0;
    int front=n+1,rear=n;
    int k=n+1;
    while(n)
    {
        int j=n;
        while(b[j-1]==b[n]&&j>=1) j--;
        k=min(k,j);
        while(a[k]!=b[n]&&k>=1) k--;
        if(!k) {Chtholly=false;break;}
        while(front<=rear&&pos[rear]-cnt>n) rear--;
        cnt++;
        front--;
        pos[front]=k+cnt;
        ans[front]=cnt;
        Ans=max(Ans,cnt-ans[rear]+1);
        n=j-1;
    }
    if(!Chtholly) {puts("-1");return 0;}
    printf("%d\n",Ans);
    return 0;
}
