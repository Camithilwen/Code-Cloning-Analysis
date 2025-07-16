#include<bits/stdc++.h>
#define Fail puts("NO"),exit(0);
#define eps 1e-10
#define maxn 505
#define maxm 4010
#define inf 1000000007
#define mod 998244353
#define pi acos(-1)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef bitset<maxn> bit;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
int prime[100010],primesize;
bool notprime[100010];
void get_prime()
{
    for(int i=2;i<=100000;i++)
    {
        if(!notprime[i])   prime[++primesize]=i;
        for(int j=1;j<=primesize&&i*prime[j]<=100000;j++)
        {
            notprime[i*prime[j]]=true;
            if(i%prime[j]==0)  break;
        }
    }
}
ll ans[maxn][maxn];
int xx[4]={0,0,1,-1};
int yy[4]={1,-1,0,0};
bool check(int x,int y)
{
    return (x>=1&&x<=n&&y>=1&&y<=n);
}
ll gcd(ll x,ll y)
{
    if(!y)  return x;
    return gcd(y,x%y);
}
ll lcm(ll x,ll y)
{
    return x*(y/gcd(x,y));
}
int main()
{
    get_prime();
    n=read();
    int l=1,r=(n<<1)+(!(n&1));
    for(int i=2;i<=(n<<1);i+=2)
    {
        int val;
        if(i%4==0)  val=prime[l++];
        else        val=prime[r--];
        for(int x=1;x<=n;x++)
        {
            int y=(i-x);
            if(y<=0||y>n)  continue;
            ans[x][y]=val;
        }
    }
    for(int i=-(n-1)/2*2;i<=(n-1)/2*2;i+=2)
    {
        int val;
        if(i%4==0)  val=prime[l++];
        else        val=prime[r--];
        for(int x=1;x<=n;x++)
        {
            int y=(i+x);
            if(y<=0||y>n)  continue;
            ans[x][y]*=val;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if((i+j)&1)
            {
                for(int k=0;k<4;k++)
                {
                    int tx=i+xx[k],ty=j+yy[k];
                    if(check(tx,ty))
                    {
                        if(!ans[i][j])  ans[i][j]=ans[tx][ty];
                        else          ans[i][j]=lcm(ans[i][j],ans[tx][ty]);
                    }
                }
                ans[i][j]++;
            }
        }
    }
    if(n==2)  ans[1][2]=ans[1][2]*2-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)  printf("%lld ",ans[i][j]);
        puts("");
    }
    return 0;
}