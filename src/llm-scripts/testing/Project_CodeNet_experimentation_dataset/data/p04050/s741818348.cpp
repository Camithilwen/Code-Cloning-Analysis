#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define of(i,l,r) for(int i=l;i>=r;i--)
#define fe(i,u) for(int i=head[u];i;i=e[i].next)
using namespace std;
typedef long long ll;
inline void open(const char *s)
{
	#ifndef ONLINE_JUDGE
	char str[20];
	sprintf(str,"in%s.txt",s);
	freopen(str,"r",stdin);
//	sprintf(str,"out%s.txt",s);
//	freopen(str,"w",stdout);
	#endif
}
inline int rd()
{
	static int x,f;
	x=0;f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return f>0?x:-x;
}
const int N=110;
int n,m,a[N],b[N],t=0;

int main()
{
	n=rd();m=rd();
	fo(i,1,m)a[i]=rd(),t+=(a[i]&1);
	if(m==1){
		if(a[1]==1)puts("1\n1\n1");
		else printf("%d\n2\n%d %d",a[1],1,a[1]-1);
		return 0;
	}
	if(t>2){puts("Impossible");return 0;}
	fo(i,2,m)if(a[i]&1)a[1]&1?swap(a[m],a[i]):swap(a[1],a[i]);
	t=0;
	if(a[1]>1)b[t=1]=a[1]-1;
	fo(i,2,m)b[++t]=a[i];b[t]++;
	fo(i,1,m)cout<<a[i]<<' ';cout<<endl;
	cout<<t<<endl;
	fo(i,1,t)cout<<b[i]<<' ';cout<<endl;
	return 0;
}
