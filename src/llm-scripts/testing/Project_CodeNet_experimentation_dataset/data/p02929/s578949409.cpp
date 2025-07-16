#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
#define mod 1000000007
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 200005
int a[N];
char s[N];
int n;
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n*2;i++)
	{
		a[i]=(s[i]=='B');
	}
	int cur=0,ans=1;
	for(int i=1;i<=n*2;i++)
	{
		if((cur&1)==a[i])
		{
			ans=ans*cur%mod;
			cur--;
		}
		else cur++;
	}
	if(cur!=0) return cout<<"0\n",0;
	for(int i=1;i<=n;i++)
	{
		ans=ans*i%mod;
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}

