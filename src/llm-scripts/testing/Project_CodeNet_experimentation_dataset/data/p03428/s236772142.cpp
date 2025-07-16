#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int INF=1e9;
const long double eps=1e-9;
const double Pi=acos(-1.0);
const int maxn=1e2+10;
struct node{
	int x,y,id;
}a[maxn];
inline bool cmp(const node &lhs,const node &rhs){
	return lhs.x==rhs.x?lhs.y>rhs.y:lhs.x<rhs.x;
}
inline bool Cmp(const node &lhs,const node &rhs){
	return lhs.id<rhs.id;
}
int stk[maxn],ans[maxn],vis[maxn];
double Ans[maxn],slp[maxn];
inline int read(){
	int x=0,flag=1;
	char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')flag=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x*flag;
}
inline double Slope(int idx,int idy){
	if(a[idx].x==a[idy].x)return -INF;
	return (a[idx].y-a[idy].y)*1.0/(a[idx].x-a[idy].x);
}
inline double arcle(int idx,int idy){
	if(a[idx].x==a[idy].x){
		if(a[idx].y>a[idy].y)return 0;
		else return Pi;
	}
	if(a[idx].y==a[idy].y){
		if(a[idx].x<a[idy].x)return Pi/2;
		else return 3*Pi/2;
	}
	double slope=-1.0/Slope(idx,idy),arc=atan(slope);
	if(arc<0)arc+=Pi;
	if(a[idx].x<a[idy].x)return arc;
	else return arc+Pi;
}
int main(){
	int i,j,k,m,n,pos;
	n=read();
	for(i=1;i<=n;i++){
		a[i].x=read();a[i].y=read();a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	stk[1]=1;stk[2]=2;int top=2;
	for(i=3;i<=n;i++){
		while(top>1 && Slope(stk[top],stk[top-1])>=Slope(i,stk[top]))top--;
		stk[++top]=i;
	}
	for(i=1;i<top;i++)ans[i]=a[stk[i]].id,vis[a[stk[i]].id]=1;pos=top;
	vis[a[1].id]=0;
	reverse(a+1,a+n+1);
	stk[1]=1;stk[2]=2;top=2;
	for(i=3;i<=n;i++){
		if(vis[a[i].id])continue;
		while(top>1 && Slope(stk[top],stk[top-1])>=Slope(i,stk[top]))top--;
		stk[++top]=i;
	}
	for(i=pos;i<pos+top-1;i++)ans[i]=a[stk[i-pos+1]].id;pos=pos+top-2;
	sort(a+1,a+n+1,Cmp);
	ans[0]=ans[pos];ans[pos+1]=ans[1];
	for(i=0;i<=pos;i++)slp[i]=arcle(ans[i+1],ans[i]);
	for(i=1;i<=pos;i++)Ans[ans[i]]=slp[i]-slp[i-1];
	for(i=1;i<=n;i++){
		if(Ans[i]<0)Ans[i]+=2*Pi;
		printf("%.15lf\n",Ans[i]/(2*Pi));
	}
	return 0;
}
