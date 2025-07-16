#include<queue>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include <cstring>
#include <string.h>
#include <cmath>
#include <math.h>
#include <time.h>
#define ll long long
#define N 100003
#define M 103
#define db double
#define P putchar
#define G getchar
#define inf 998244353
using namespace std;
char ch;
void read(int &n)
{
	n=0;
	ch=G();
	while((ch<'0' || ch>'9') && ch!='-')ch=G();
	ll w=1;
	if(ch=='-')w=-1,ch=G();
	while('0'<=ch && ch<='9')n=(n<<3)+(n<<1)+ch-'0',ch=G();
	n*=w;
}

int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
ll abs(ll x){return x<0?-x:x;}
ll sqr(ll x){return x*x;}
void write(ll x){if(x>9) write(x/10);P(x%10+'0');}

int n,a[N],ans,s;
bool pd; 

int gcd(int x,int y){return y==0?x:gcd(y,x%y);}

bool dfs(int x)
{
	s=pd=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)pd=1;
		if(a[i]&1)s++;
	}
	
	if((n-s)&1)return x;
	if(pd || s>1)return !x;
	
	for(int i=1;i<=n;i++)
		if(a[i]%2)
		{
			a[i]--;
			break;
		}
	
	int gc=a[1];
	for(int i=2;i<=n;i++)
		gc=gcd(gc,a[i]);
	for(int i=1;i<=n;i++)
		a[i]/=gc;
	return dfs(!x);
}

int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	
	read(n);
	for(int i=1;i<=n;i++)
		read(a[i]);
	
	if(dfs(1))puts("First");
		else puts("Second");
	
	return 0;
}
