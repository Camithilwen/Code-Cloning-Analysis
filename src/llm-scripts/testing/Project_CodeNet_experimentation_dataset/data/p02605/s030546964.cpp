#define DIN freopen("input.txt","r",stdin);
#define DOUT freopen("output.txt","w",stdout);
#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
#define REP(i,a,b) for(int i=(a);i<=(int)(b);i++)
#define REP_(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<LL,LL> P;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}

const int maxn=1e6+5,v=5e5,N=1e6;
struct node {int x,y,dir;} a[maxn];
VI x[maxn],y[maxn],p[maxn],q[maxn];
int n,ans=1e9;
char s[10];
bool cmp1(int i,int j) {return a[i].x==a[j].x?a[i].y<a[j].y:a[i].x<a[j].x;}
bool cmp2(int i,int j) {return a[i].y==a[j].y?a[i].x<a[j].x:a[i].y<a[j].y;}

int main()
{
    n=read();
    REP(i,1,n)
    {
        a[i].x=read();
        a[i].y=read();
        scanf("%s",s);
        a[i].dir=s[0];
    }
    sort(a+1,a+n+1,[&](node a,node b){return a.x==b.x?a.y<b.y:a.x<b.x;});
    REP(i,2,n) if(a[i].x==a[i-1].x && a[i].y==a[i-1].y) return puts("0"),0;
    REP(i,1,n)
    {
        x[a[i].x+v].pb(i);
        y[a[i].y+v].pb(i);
        p[a[i].y-a[i].x+v].pb(i);
        q[a[i].y+a[i].x+v].pb(i);
    }

    REP(i,1,N)
    {
        sort(x[i].begin(),x[i].end(),cmp1);
        sort(y[i].begin(),y[i].end(),cmp2);
        sort(p[i].begin(),p[i].end(),cmp1);
        sort(q[i].begin(),q[i].end(),cmp1);
    }

    REP(i,1,N) if(x[i].size()>1)
    {
        int yy=-1;
        REP(j,0,x[i].size()-1)
        {
            int id=x[i][j];
            if(yy>=0 && a[id].dir=='D') ans=min(ans,abs(a[id].y-yy)*5);
            if(a[id].dir=='U') yy=a[id].y;
        }
    }
    REP(i,1,N) if(y[i].size()>1)
    {
        int xx=-1;
        REP(j,0,y[i].size()-1)
        {
            int id=y[i][j];
            if(xx>=0 && a[id].dir=='L') ans=min(ans,abs(a[id].x-xx)*5);
            if(a[id].dir=='R') xx=a[id].x;
        }
    }
    REP(i,1,N) if(p[i].size()>1)
    {
        int xx1=-1,xx2=-1;
        REP(j,0,p[i].size()-1)
        {
            int id=p[i][j];
            if(xx1>=0 && a[id].dir=='L') ans=min(ans,abs(a[id].x-xx1)*10);
            if(xx2>=0 && a[id].dir=='D') ans=min(ans,abs(a[id].x-xx2)*10);
            if(a[id].dir=='U') xx1=a[id].x;
            if(a[id].dir=='R') xx2=a[id].x;
        }
    }
    REP(i,1,N) if(q[i].size()>1)
    {
        int xx1=-1,xx2=-1;
        REP(j,0,q[i].size()-1)
        {
            int id=q[i][j];
            if(xx1>=0 && a[id].dir=='U') ans=min(ans,abs(a[id].x-xx1)*10);
            if(xx2>=0 && a[id].dir=='L') ans=min(ans,abs(a[id].x-xx2)*10);
            if(a[id].dir=='R') xx1=a[id].x;
            if(a[id].dir=='D') xx2=a[id].x;
        }
    }
    if(ans>=(1e9)-1) puts("SAFE");
    else printf("%d\n",ans);

    return 0;
}
