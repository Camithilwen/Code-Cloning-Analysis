#include<bits/stdc++.h>
using namespace std;
int flip[2],mv[2];
vector <int> vec[2];
bool vis[1000100];
int a[1000100],b[1000100],c[1000100],go[1000100];
int work(vector <int> &vec)
{
	//for (int i=0;i<vec.size();i++) cout<<vec[i]<<' ';cout<<"\n\n";
	int ans=0;
	memset(vis,0,sizeof(vis));
	for (int i=0;i<vec.size();i++) if (!vis[i])
	{
		int now=i;
		while (!vis[now])
		{
			vis[now]=true;
			ans++;
			now=vec[now];
		}
		ans--;
	}
	return ans&1;
}
int main()
{
	int n;scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=1;i<=n;i++)
	{
		if ((a[i]+1==b[i])&&(b[i]+1==c[i])) {go[i]=c[i];}
		else if ((c[i]+1==b[i])&&(b[i]+1==a[i])) {flip[i&1]^=1;go[i]=a[i];}
		else {printf("No\n");return 0;}
		
		if (((go[i]/3)&1)!=(i&1)) {printf("No\n");return 0;}
		vec[i&1].push_back((go[i]/3-1)/2);
	}
	mv[0]=work(vec[0]);mv[1]=work(vec[1]);
	puts(((mv[0]==flip[1])&&(mv[1]==flip[0]))?"Yes":"No");
}