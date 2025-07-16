#include <bits/stdc++.h>
#define res register int
#define ll long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define INF 1000000007
#define gc getchar()
#define MAXN 200005
#define lc pos<<1
#define rc pos<<1|1
using namespace std;

inline int read()
{
    int ch=gc,f=0;
    int x=0;
    while(ch<'0'||ch>'9')
    {
        f|=ch=='-';
        ch=gc;
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=gc;
    }
    return f?-x:x;
}
struct row
{
	int c,flag;
}r[MAXN];
int n,m;
int a[4][MAXN],t[2],c[MAXN];
inline void hult()
{
	printf("No\n");
	exit(0);
}
inline void op(int i)
{
	if(i<1)
	hult();
	swap(r[i],r[i+2]);
	r[i].flag^=1;
	r[i+1].flag^=1;
	r[i+2].flag^=1;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	a[1][i]=read();
	for(int i=1;i<=n;i++)
	a[2][i]=read();
	for(int i=1;i<=n;i++)
	a[3][i]=read();
	for(int i=1;i<=n;i++)
	{
		int b[3]={a[1][i],a[2][i],a[3][i]};
		sort(b,b+3);
		if(b[2]%3||b[1]!=b[2]-1||b[0]!=b[1]-1)
		hult();
		if(a[2][i]!=b[1])
		hult();
		r[i].c=b[2]/3;
		r[i].flag=b[2]==a[3][i];
		c[i]=r[i].c;
		if(abs(r[i].c-i)&1)
		hult();
		t[i&1]^=b[2]==a[1][i];
	}
    for(res i=1;i<=n;i++)
	{
        while(c[i]!=i)
		{
            t[i&1^1]^=1;
            swap(c[i],c[c[i]]);
        }
    }
    puts(t[0]||t[1]?"No":"Yes");
	return 0;
}