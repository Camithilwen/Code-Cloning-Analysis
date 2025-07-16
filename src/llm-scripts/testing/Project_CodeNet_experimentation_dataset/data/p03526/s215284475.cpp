#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define int long long
#define INF (int)(1e18)
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 5005
int f[N][N];
struct Node
{
	int x,y;
};
Node a[N];
bool cmp(Node x,Node y)
{
	return x.x+x.y<y.x+y.y;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++) a[i].x=read(),a[i].y=read();
	sort(a+1,a+n+1,cmp);
	for(int i=0;i<=n;i++)
	{
		for(int j=1;j<=n;j++) f[i][j]=INF;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			f[i][j]=f[i-1][j];
			if(f[i-1][j-1]<=a[i].x)
			{
				f[i][j]=min(f[i][j],f[i-1][j-1]+a[i].y);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(f[n][i]<INF) ans=i;
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}

