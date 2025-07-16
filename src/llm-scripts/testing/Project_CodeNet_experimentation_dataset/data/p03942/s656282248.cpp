#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
template <typename T>inline T read()
{
    register T sum=0;
    register char cc=getchar();
    int sym=1;
    while(cc!='-'&&(cc>'9'||cc<'0'))cc=getchar();
    if(cc=='-')sym=-1,cc=getchar();
    sum=sum*10+cc-'0';
    cc=getchar();
    while(cc>='0'&&cc<='9')sum=sum*10+cc-'0',cc=getchar();
    return sym*sum;
}
template <typename T>inline T read(T &a)
{
    a=read<T>();
    return a;
}
template <typename T,typename... Others> inline void read(T& a, Others&... b)
{
    a=read(a);
	read(b...);
}
int n,up,down,ans;
char s[maxn],t[maxn];
queue<int>Q;
int main()
{
	read(n);
	scanf("%s %s",s+1,t+1);
	if(strcmp(s+1,t+1)==0)
	{
		puts("0");
		return 0;
	}
	up=n,down=n;
	while(down)
	{
		while(down>1&&t[down-1]==t[down])
			down-=1;
		while(up&&(up>down||s[up]!=t[down]))
			up-=1;
		if(!up)
		{
			puts("-1");
			return 0;
		}
		while(!Q.empty()&&Q.front()-(int)Q.size()>=down)
			Q.pop();
		if(up!=down)
			Q.push(up);
		ans=max(ans,(int)Q.size()+1);
		down-=1;
	}
	printf("%d\n",ans);
    return 0;
}
