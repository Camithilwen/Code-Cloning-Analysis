#include<iostream>
#include<cstring>
#include<cstdio>
#include<bitset>
#define MN 100
#define ull unsigned long long
#define F(a,b,c,d) ((a>b||c>d)?ans:f[num[a][b]][num2[c][d]])
#define N 65535
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char st[MN+5][MN+5];
int f[5505][5505],num[MN+5][MN+5],num2[MN+5][MN+5],n,m,ans,cnt[1<<16],s[MN+5][MN+5];
inline void R(int&x,int y){y>x?x=y:0;}
/*struct Bitset
{
    ull a,b;
    Bitset(){a=b=0;}
    Bitset(ull c,ull d):a(c),b(d){}
    void Mod(int y){y>=64?(b|=1ULL<<y-64):(a|=1ULL<<y);}
    Bitset operator & (const Bitset&c){return Bitset(a&c.a,b&c.b);}
    int Count(){return cnt[a&N]+cnt[a>>16&N]+cnt[a>>32&N]+cnt[a>>48&N]
                      +cnt[b&N]+cnt[b>>16&N]+cnt[b>>32&N]+cnt[b>>48&N];}
    Bitset operator << (int y){return y>=64?Bitset(0,a<<y-64):Bitset(a<<y,b<<y|(a>>64-y));}
};*/
bitset<105> lru[MN+5][MN+5],lrd[MN+5][MN+5],udl[MN+5][MN+5],udr[MN+5][MN+5],a[MN+5],b[MN+5];
inline int C(int u,int l,int d,int r){return s[d][r]-s[u-1][r]-s[d][l-1]+s[u-1][l-1];}
int main()
{
    for(int i=1;i<=N;++i) cnt[i]=cnt[i>>1]+(i&1);
    n=read();m=read();
    for(int i=1,k=0;i<=n;++i)for(int j=i;j<=n;++j)num[i][j]=++k;
    for(int i=1,k=0;i<=m;++i)for(int j=i;j<=m;++j)num2[i][j]=++k;
    for(int i=1;i<=n;++i) scanf("%s",st[i]+1);
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
    {
        if(st[i][j]=='o') a[i][j]=1,b[j][i]=1;
        s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(st[i][j]=='E');
    }
    for(int i=1;i<=m;++i) for(int j=1;j<=n;++j)
        for(int k=1;k<=i;++k)
        {
            if(C(1,k,n-j+1,m-(i-k))) lru[i][j][k]=1;
            if(C(j,k,n,m-(i-k)))     lrd[i][j][k]=1;
        }
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)
        for(int k=1;k<=i;++k)
        {
            if(C(k,1,n-(i-k),m-j+1)) udl[i][j][k]=1;
            if(C(k,j,n-(i-k),m))     udr[i][j][k]=1;
        }
    for(int i=1;i<=n;++i) for(int j=n;j>=i;--j)
        for(int k=1;k<=m;++k) for(int l=m;l>=k;--l)
        {
            int v=F(i,j,k,l);
            R(F(i+1,j,k,l),v+(a[i]&(lru[l-k+1][j-i+1]<<k-1)).count());
            R(F(i,j-1,k,l),v+(a[j]&(lrd[l-k+1][j-i+1]<<k-1)).count());
            R(F(i,j,k+1,l),v+(b[k]&(udl[j-i+1][l-k+1]<<i-1)).count());
            R(F(i,j,k,l-1),v+(b[l]&(udr[j-i+1][l-k+1]<<i-1)).count());
        }
    printf("%d\n",ans);
    return 0;
}
