// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

void nosol(){puts("No");exit(0);}
int n,a[3][100111],rev[2],ord[2][100111];
int bit[100111];
void add(int x){for(;x<100111;x+=x&-x)bit[x]^=1;}
int query(int x){int ret=0;for(;x;x-=x&-x)ret^=bit[x];return ret;}
int getinv(int a[],int n)
{
	memset(bit,0,sizeof(bit));
	int ret=0;
	for(int i=0;i<n;i++)
	{
		ret^=(i&1)^query(a[i]);
		add(a[i]+1);
	}
	return ret;
}
int main()
{
	get1(n);
	for(int i=0;i<3;i++)for(int j=0;j<n;j++){get1(a[i][j]);a[i][j]--;}
	for(int i=0;i<n;i++)
	{
		if(a[0][i]/3!=a[1][i]/3||a[0][i]/3!=a[2][i]/3)nosol();
		if(a[0][i]/3%2!=i%2)nosol();
		if(a[1][i]*2!=a[0][i]+a[2][i])nosol();
		rev[i&1]^=(a[0][i]>a[1][i]);
		ord[i&1][i>>1]=a[0][i]/3;
	}
	if(getinv(ord[0],n+1>>1)!=rev[1])nosol();
	if(getinv(ord[1],n>>1)!=rev[0])nosol();
	puts("Yes");
	return 0;
}