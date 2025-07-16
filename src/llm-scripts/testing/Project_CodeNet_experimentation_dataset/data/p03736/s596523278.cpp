#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int gi()
{
	char c;int num=0,flg=1;
	while((c=getchar())<'0'||c>'9')if(c=='-')flg=-1;
	while(c>='0'&&c<='9'){num=num*10+c-48;c=getchar();}
	return num*flg;
}
#define N 200005
#define LL long long
#define lc i<<1
#define rc i<<1|1
const LL INF=0x3f3f3f3f3f3f3f3fll;
int pos[N],A,B,n,Q;
struct node{
	int l,r;
	LL mi1,mi2,la;
}a[N<<2];
void cal(int i,LL k){a[i].mi1+=k;a[i].mi2+=k;a[i].la+=k;}
void pushdown(int i)
{
	if(a[i].la&&a[i].l<a[i].r){
		cal(lc,a[i].la);cal(rc,a[i].la);
		a[i].la=0;
	}
}
void pushup(int i)
{
	a[i].mi1=min(a[lc].mi1,a[rc].mi1);
	a[i].mi2=min(a[lc].mi2,a[rc].mi2);
}
void build(int i,int l,int r)
{
	a[i].l=l;a[i].r=r;
	if(l==r){
		a[i].mi1=INF;a[i].mi2=INF;
		return;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);build(rc,mid+1,r);
	pushup(i);
}
void insert(int i,int l,int r,LL k)
{
	if(a[i].l>r||a[i].r<l)return;
	pushdown(i);
	if(l<=a[i].l&&a[i].r<=r){cal(i,k);return;}
	insert(lc,l,r,k);insert(rc,l,r,k);
	pushup(i);
}
void modify(int i,int x,LL k)
{
	if(a[i].l>x||a[i].r<x)return;
	pushdown(i);
	if(x==a[i].l&&a[i].r==x){a[i].mi1=min(a[i].mi1,k-x);a[i].mi2=min(a[i].mi2,k+x);return;}
	modify(lc,x,k);modify(rc,x,k);
	pushup(i);
}
LL query1(int i,int l,int r)
{
	if(a[i].l>r||a[i].r<l)return INF;
	pushdown(i);
	if(l<=a[i].l&&a[i].r<=r)return a[i].mi1;
	return min(query1(lc,l,r),query1(rc,l,r));
}
LL query2(int i,int l,int r)
{
	if(a[i].l>r||a[i].r<l)return INF;
	pushdown(i);
	if(l<=a[i].l&&a[i].r<=r)return a[i].mi2;
	return min(query2(lc,l,r),query2(rc,l,r));
}
LL query(int i)
{
	if(a[i].l==a[i].r)return a[i].mi1+a[i].l;
	pushdown(i);
	return min(query(lc),query(rc));
}
int ab(int x){return x<0?-x:x;}
int main()
{
	int i;LL f;
	n=gi();Q=gi();A=gi();B=gi();
	build(1,1,n);
	pos[0]=A;modify(1,B,0);
	for(i=1;i<=Q;i++){
		pos[i]=gi();
		f=min(query1(1,1,pos[i])+pos[i],query2(1,pos[i]+1,n)-pos[i]);
		insert(1,1,n,ab(pos[i]-pos[i-1]));
		modify(1,pos[i-1],f);
	}
	printf("%lld\n",query(1));
}