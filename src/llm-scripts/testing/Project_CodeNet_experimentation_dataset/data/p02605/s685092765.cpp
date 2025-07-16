#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
const long long inf=0x3f3f3f3f;
struct pl
{
	long long x;long long y;long long jyz;	
}p1[N];
vector <pl> xxx[N],yyy[N],zzz[N*2],fff[N*2];
long long cntx,cnty,cntz,cntf,n,ans=inf;
string s;
bool cjy(pl a,pl b)
{
	if (a.x>b.x) return 0;
	if (a.x<b.x) return 1;
	return a.y<b.y;
}
signed main()
{
	;;;;;
	cin>>n;
	for (long long i=1;i<=n;i++)
	{
		scanf("%lld%lld",&p1[i].x,&p1[i].y);
		cin>>s;
		if (s=="U") p1[i].jyz=1;
		if (s=="R") p1[i].jyz=2;
		if (s=="D") p1[i].jyz=3;
		if (s=="L") p1[i].jyz=4;
	}
	sort(p1+1,p1+n+1,cjy);
	for (long long i=1;i<=n;i++)
	{
		xxx[p1[i].x].push_back(p1[i]);
		yyy[p1[i].y].push_back(p1[i]);
		fff[p1[i].x+p1[i].y].push_back(p1[i]);
		zzz[p1[i].x-p1[i].y+N-5].push_back(p1[i]);
	}
	for (long long i=0;i<N;i++) if (xxx[i].size()>=2)
	{
		long long tans=inf,ty=-1;
		for (long long j=0;j<xxx[i].size();j++)
		{
			if (xxx[i][j].jyz==1) ty=xxx[i][j].y;
			if (xxx[i][j].jyz==3&&ty!=-1) tans=min(tans,xxx[i][j].y-ty); 
		}
		ans=min(ans,5*tans);
	}
	for (long long i=0;i<N;i++) if (yyy[i].size()>=2)
	{
		long long tans=inf,tx=-1;
		for (long long j=0;j<yyy[i].size();j++)
		{
			if (yyy[i][j].jyz==2) tx=yyy[i][j].x;
			if (yyy[i][j].jyz==4&&tx!=-1) tans=min(tans,yyy[i][j].x-tx); 
		}
		ans=min(ans,5*tans);
	}
	for (long long i=0;i<2*N;i++) if (fff[i].size()>=2)
	{
		long long tans=inf,td=-1,tr=-1;
		for (long long j=0;j<fff[i].size();j++)
		{
			if (fff[i][j].jyz==2) tr=fff[i][j].x;
			if (fff[i][j].jyz==3) td=fff[i][j].x;
			if (fff[i][j].jyz==1&&tr!=-1) tans=min(tans,fff[i][j].x-tr); 
			if (fff[i][j].jyz==4&&td!=-1) tans=min(tans,fff[i][j].x-td); 
		}
		ans=min(ans,10*tans);
	}
	for (long long i=0;i<2*N;i++) if (zzz[i].size()>=2)
	{
		long long tans=inf,tu=-1,tr=-1;
		for (long long j=0;j<zzz[i].size();j++)
		{
			if (zzz[i][j].jyz==2) tr=zzz[i][j].x;
			if (zzz[i][j].jyz==1) tu=zzz[i][j].x;
			if (zzz[i][j].jyz==3&&tr!=-1) tans=min(tans,zzz[i][j].x-tr); 
			if (zzz[i][j].jyz==4&&tu!=-1) tans=min(tans,zzz[i][j].x-tu); 
		}
		ans=min(ans,10*tans);
	}
	if (ans==inf) cout<<"SAFE"<<endl;
	else cout<<ans<<endl;
}