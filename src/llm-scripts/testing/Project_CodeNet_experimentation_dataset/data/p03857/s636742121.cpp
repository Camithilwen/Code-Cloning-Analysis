#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    register int x=0;
    register char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9')
        x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x;
}
inline void write(int x)
{
	register char st[10];
	register int top=0;
	if(!x)
		putchar('0');
	while(x) 
		st[++top]=(x%10)+48,x/=10;
   	while(top)
		putchar(st[top--]);
	putchar('\n');
}
const int N=200001;
int f1[N],f2[N];
int find(int x,int *f)
{
	return f[x]==x? f[x]:f[x]=find(f[x],f);
}
map<pair<int,int>,int>mp;
int main()
{
	register int n=read(),k=read(),l=read(),a,b;
	for(register int i=1;i<=n;++i)
		f1[i]=f2[i]=i;
	while(k--)
		if(find(a=read(),f1)!=find(b=read(),f1))
			f1[find(a,f1)]=find(b,f1);
	while(l--)
		if(find(a=read(),f2)!=find(b=read(),f2))
			f2[find(a,f2)]=find(b,f2);
	for(register int i=1;i<=n;++i)
		find(i,f1),find(i,f2);
	for(register int i=1;i<=n;++i)
		++mp[make_pair(f1[i],f2[i])];
	for(register int i=1;i<=n;++i)
		write(mp[make_pair(f1[i],f2[i])]);
	return 0;
}