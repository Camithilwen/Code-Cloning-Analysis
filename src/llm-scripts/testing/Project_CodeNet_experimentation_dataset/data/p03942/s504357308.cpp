#include<bits/stdc++.h>
#define LL long long

using namespace std;
const int N=1e6+10;
int rd()
{
    int x=0,w=1;char ch=0;
    while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return x*w;
}
int n,q[N<<1],hd,tl,tg;
char cc[N],ss[N];

int main()
{
    ///
    n=rd();
    scanf("%s%s",cc+1,ss+1);
    hd=n+1,tl=n;
    int ans=0;
    for(int i=n,j=n;i;--i)
    {
	while(j&&(i<j||cc[j]!=ss[i])) --j;
	if(!j){puts("-1");return 0;}
	if(i==j){hd=n+1,tl=n,tg=0;continue;}
	if(hd>tl) q[++tl]=j-tg,q[++tl]=i-tg,ans=max(ans,1);
	else
	{
	    --tg;
	    q[--hd]=j-tg;
	    while(hd<=tl&&q[tl]+tg>=i) --tl;
	    q[++tl]=i-tg;
	    ans=max(ans,tl-hd);
	}
	while(i>j&&ss[i-1]==ss[i]) --i;
    }
    printf("%d\n",ans);
    return 0;
}
