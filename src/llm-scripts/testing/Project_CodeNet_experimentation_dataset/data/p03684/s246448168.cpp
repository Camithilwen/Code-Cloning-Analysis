#include<bits/stdc++.h>

using namespace std;
inline void read(long long &x) {
    char ch;
    bool flag = false;
    for (ch = getchar(); !isdigit(ch); ch = getchar())if (ch == '-') flag = true;
    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    x = flag ? -x : x;
}
inline void write(long long x) {
    static const long long maxlen = 100;
    static char s[maxlen];
    if (x < 0) {   putchar('-'); x = -x;}
    if (!x) { putchar('0'); return; }
    long long len = 0; for (; x; x /= 10) s[len++] = x % 10 + '0';
    for (long long i = len - 1; i >= 0; --i) putchar(s[i]);
}

inline void read(int &x){
    char ch;
    bool flag = false;
    for (ch = getchar(); !isdigit(ch); ch = getchar())if (ch == '-') flag = true;
    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    x = flag ? -x : x;
}

const long long MAXN =1001000;

long long n;
struct kt{
long long x,y;
long long id;
}a[ MAXN ];

long long fa[ MAXN ];


struct edge{
long long x,y,val;
}E[ MAXN*2 ];

bool cmp_x(kt A,kt B){
return A.x<B.x;
}

bool cmp_y(kt A,kt B){
return A.y<B.y;
}

bool cmp_e(edge A,edge B){
return A.val<B.val;
}

long long get_fa(long long x){
return (fa[x]==x)?(x):(fa[x]=get_fa(fa[x]));
}


int main(){
    read(n);
    for (long long i=1;i<=n;i++)
    {
        a[i].id=i;
        read(a[i].x);read(a[i].y);
    }
    sort(a+1,a+n+1,cmp_x);
    long long cnt=0;
    for (long long i=1;i<n;i++)
        {
            ++cnt;
            E[cnt].x=a[i].id;
            E[cnt].y=a[i+1].id;
            E[cnt].val=a[i+1].x-a[i].x;
        }

    sort(a+1,a+n+1,cmp_y);
    for (long long i=1;i<n;i++)
        {
            ++cnt;
            E[cnt].x=a[i].id;
            E[cnt].y=a[i+1].id;
            E[cnt].val=a[i+1].y-a[i].y;
        }
    for (long long i=1;i<=n;i++)
        fa[i]=i;

    sort(E+1,E+cnt+1,cmp_e);
    long long ans=0;
    for (long long i=1;i<=cnt;i++)
        {
            long long a=E[i].x,b=E[i].y;
            long long x=get_fa(a),y=get_fa(b);
            if ( x!=y )
                {
                    ans+=E[i].val;
                    fa[x]=y;
                }
        }
    cout<<ans<<endl;
    return 0;
}
