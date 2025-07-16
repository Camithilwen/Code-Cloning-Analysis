#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
struct node{
	int pos,num;
	bool operator<(const node& a)const{
		return num<a.num;
	}
};
struct node1{
	int pos,num;
	bool operator<(const node1& a)const{
		return pos<a.pos;
	}
};
char s[maxn];
bool vis[maxn]={0};
node p[maxn]={0},p1[maxn]={0};
node1 p2[maxn]={0};
ll ans[maxn]={0};
ll sum[maxn]={0};
int k[100];
int main()
{
	int n;
	scanf("%d %s",&n,s+1);
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d",&k[i]);
	}
	int num=0;
	int now1=0,now2=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='M')num++;
		else if(s[i]=='D'){
			p1[++now1].pos=i;
			p1[now1].num=num;
		}
		else if(s[i]=='C'){
			p[++now2].pos=i;
			p[now2].num=num;
			p2[now2].pos=i;
			p2[now2].num=num;
		}
	}
	for(int i=1;i<=now2;i++){
		sum[i]=sum[i-1]+p[i].num;
	}
	for(int j=1;j<=q;j++)
	{
		ll sum1=0;
	for(int i=1;i<=now1;i++){
		node aa;
		node1 bb;
		aa.num=p1[i].num+1;
		bb.pos=p1[i].pos+k[j];
		int x=lower_bound(p+1,p+now2+1,aa)-p;
		int y=lower_bound(p2+1,p2+now2+1,bb)-p2;
		y--;
		if(x==now2+1)continue;
		sum1+=sum[y]-sum[x-1]-p1[i].num*1ll*(y-x+1);
	}
	ans[j]=sum1;
}
	for(int i=1;i<=q;i++){
		printf("%lld\n",ans[i]);
	}
}