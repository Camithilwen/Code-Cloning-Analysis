#include<bits/stdc++.h>
#define N 200005
#define reg register 
#define LL long long 
using namespace std;

int val,cnt;
int n,a[N],b[N];
vector<int> p,q;

inline int qr()
{
	int x=0,w=1;char a=0;
	while(a<'0'||a>'9'){if(a=='-')w=-1;a=getchar();}
	while(a<='9'&&a>='0'){x=(x<<3)+(x<<1)+(a^48);a=getchar();}
	return x*w;
}

inline LL qrl()
{
	LL x=0,w=1;char a=0;
	while(a<'0'||a>'9'){if(a=='-')w=-1;a=getchar();}
	while(a<='9'&&a>='0'){x=(x<<3)+(x<<1)+(a^48);a=getchar();}
	return x*w;
}

bool mycmp(int a,int b)
{
	return a>b;
}

int main()
{
	n=qr();
	for(register int i=1;i<=n;i++)
		a[i]=qr();
	for(register int i=1;i<=n;i++)
		b[i]=qr();
	sort(b+1,b+n+1,mycmp);
	for(register int i=1;i<=n;i++)
	{
		if(a[i]!=b[i])
			continue;
		cnt++;
		p.push_back(i);
		val=b[i];
	}
	for(register int i=1;i<=n;i++)
	{
		if(!cnt)
			break;
		if(a[i]==b[i])
			continue;
		if(a[i]!=val&&b[i]!=val)
		{
			cnt--;
			q.push_back(i);
		}
	}
	if(cnt)
	{
		printf("No\n");
		return 0;
	}
	for(int i=0;i<q.size();i++)
		swap(b[p[i]],b[q[i]]);
	printf("Yes\n");
	for(register int i=1;i<=n;i++)
		printf("%d ",b[i]);
	printf("\n"); 
	return 0;
} 


