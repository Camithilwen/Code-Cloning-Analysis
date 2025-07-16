#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e7+5;
const long long inf=0x3f3f3f3f;
const long long mod=1e9+7;
long long n,m,a[maxn],b[maxn],cx[maxn],cy[maxn],px[maxn],py[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m;
	memset(px,-1,sizeof(px));
	memset(py,-1,sizeof(py));
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		cx[a[i]]++;
		px[a[i]]=i;
	}
	for(long long i=1;i<=m;i++)
	{
		cin>>b[i];
		cy[b[i]]++;
		py[b[i]]=i;
	}
	for(long long i=1;i<=n*m;i++)
	{
		if(cx[i]>2||cy[i]>2)
		{
			cout<<"0"<<endl;
			return 0;
		}
	}
	long long nn=0,mm=0,ans=1,cnt=0;
	for(long long i=n;i>0;i--)
	{
		for(long long j=m;j>0;j--)
		{
			long long x=(i-1)*m+j;
			if(px[x]!=-1&&py[x]!=-1)
			{
				nn++;
				mm++;
				cnt++;
			}
			else if(px[x]!=-1)
			{
				if(!mm)
				{
					cout<<"0"<<endl;
					return 0;
				}
				nn++;
				cnt++;
				ans=ans*mm%mod;
			}
			else if(py[x]!=-1)
			{
				if(!nn)
				{
					cout<<"0"<<endl;
					return 0;
				}
				mm++;
				cnt++;
				ans=ans*nn%mod;
			}
			else
			{
				if(nn*mm-cnt==0)
				{
					cout<<"0"<<endl;
					return 0;
				}
				ans=ans*(nn*mm-cnt)%mod;
				cnt++;
			}
			if(mm>m||nn>n)
			{
				cout<<"0"<<endl;
				return 0;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

/*
2 2
4 3
3 4
*/
