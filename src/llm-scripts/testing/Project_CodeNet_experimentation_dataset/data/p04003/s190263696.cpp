#include<bits/stdc++.h>
using namespace std;
#define f1(a,b,c) for(int c=a;c<=b;c++)
#define f2(a,b,c) for(int c=a;c>=b;c--)
#define f3(a,b,c) for(int c=a;c;c=b)
#define so1(a,n) sort(a+1,a+n+1,mycmp);
#define so2(a,n) sort(a+1,a+n+1);
#define ll long long
#define itn int
#define ubt int 
#define pii pair<int,int>
#define mp make_pair
const int twx=1e6+100;
const int inf=0x7fffffff;
ll read()
{
    ll sum=0;
    ll flag=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
        {
            flag=-1;
        }
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        sum=((sum*10)+c-'0');
        c=getchar();
    }
    return sum*flag;
}
int n,m;
struct LV
{
    int Next;
    int y;
    int v;
}a[twx<<1];
int Link[twx];
int len;
map<pii,int> p;
int cnt=0;
bool v[twx];
int d[twx];
void Insert(int x,int y,int z)
{
    a[++len].y=y;
    a[len].Next=Link[x];
    a[len].v=z;
    Link[x]=len;
}
int get(int x,int y)
{
    if(p.find(mp(x,y))!=p.end())
    {
        return p[mp(x,y)];     
    }
    else
    {
        return p[mp(x,y)]=++cnt;
    }
}
void spfa()
{
    memset(d,0x3f,sizeof d);
    queue<int> q;
    q.push(1);
    v[1]=1;
    d[1]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        f3(Link[x],a[i].Next,i)
        {
            int y=a[i].y;
            int vs=a[i].v;
            if(d[y]>d[x]+vs)
            {
                d[y]=d[x]+vs;
                if(!v[y])
                {
                    v[y]=1;
                    q.push(y);
                }
            }
        }
        v[x]=0;
    }
}
void init()
{
	n=read();
    m=read();
    cnt=n;
    f1(1,m,i)
    {
        int x=read();
        int y=read();
        int z=read();
        int xz=get(x,z);
        int yz=get(y,z);
        Insert(xz,yz,0);
        Insert(yz,xz,0);
        Insert(x,xz,1);
        Insert(xz,x,1);
        Insert(y,yz,1);
        Insert(yz,y,1);
    }
    spfa();
    printf("%d\n",d[n]==0x3f3f3f3f?-1:d[n]/2);
}
void work()
{
	
}
void print()
{
	
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
    init();
	return 0;
}
