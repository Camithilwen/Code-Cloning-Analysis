#include<bits/stdc++.h>

using namespace std;

#define fo(i,a,b) for (int i=a;i<=b;i++)
#define fd(i,a,b) for (int i=a;i>=b;i--)
#define fi first
#define se second	
#define mkp make_pair

typedef long long ll;

const int N=1100000;

int n,ans,flag,s[N],t[N],pos[N],a[N],b[N];

int read()
{
	int ret=0,sig=1;
	char c;
	while (c=getchar(),(c<'0'||c>'9')&&c!='-');
	if (c=='-') sig=-1;
	else ret=c-'0';
	while (c=getchar(),c>='0'&&c<='9') ret=ret*10+c-'0';
	return ret*sig;
}

int main()
{
	n=read();
	fo(i,1,n)
	{
		char c;
		while (c=getchar(),c<'a'||c>'z');
		s[i]=c-'a'+1;
	}
	fo(i,1,n)
	{
		char c;
		while (c=getchar(),c<'a'||c>'z');
		t[i]=c-'a'+1;
		if (s[i]!=t[i]) flag=1;
	}
	if (!flag) 
	{
		printf("0\n");
		return 0;
	}
	int w=n+1;
	b[0]=1;
	fd(i,n+1,1)
		if (t[i]!=t[i-1])
		{
			b[++b[0]]=i-1;
			while (w&&(w>i||s[w]!=t[i])) w--;
			if (!w)
			{
				printf("-1\n");
				return 0;
			}
			a[++a[0]]=w;
		}
	int tail=1;
	fo(i,2,a[0])
	{
		while (tail<a[0]&&a[tail+1]-(i-tail-1)>=b[i]) tail++;
		ans=max(ans,i-tail);
	}
	printf("%d\n",ans);
	return 0;
}