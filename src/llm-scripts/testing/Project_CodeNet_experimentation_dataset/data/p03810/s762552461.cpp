#include<bits/stdc++.h>

/*zzzzdfadfadfad*/
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fod(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long LL;
const int N=100500;
int read(int &n)
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}
int m,n,ans;
int a[N];
int g[N];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main()
{
    int w;
/*zzzzdfadfadfad*/
    LL q;
    read(n);
    fo(i,1,n)q+=(LL)read(a[i]);
    if(n==1&&a[1]==1)return printf("Second\n"),0;
    if(n==1)return printf("First\n"),0;
    if(!(n&1))
    {
        if(q&1)printf("First\n");
        else printf("Second\n");
        return 0;
    }
    if(!(q&1))return printf("First\n"),0;
    for(bool I=0;1;I=!I)
    {
        g[n]=a[n];
        LL t=a[n]-1;
/*zzzzdfadfadfad*/
        fod(i,n-1,1)g[i]=gcd(g[i+1],a[i]),t+=(LL)a[i];
        bool OK=0;
        q=a[1];
        if(a[1]-1&&(1&(t/(ans=gcd(g[2],a[1]-1)))))OK=1,--a[1];
        else fo(i,2,n)if(a[i]-1)
        {
            w=gcd(q,a[i]-1);
            if(i<n)w=gcd(w,g[i+1]);
            if((1&(t/(ans=w))))
            {
                OK=1,--a[i];
                break;
            }
/*zzzzdfadfadfad*/
            q=gcd(q,a[i]);
        }else break;
        if(!OK)
/*zzzzdfadfadfad*/
        {
            if(I)printf("First\n");
            else printf("Second\n");
            return 0;
        }
        fo(i,1,n)a[i]/=ans;
    }
    return 0;
}