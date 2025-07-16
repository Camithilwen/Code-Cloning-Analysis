#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
inline int read()
{
	int s=0,f=1; char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=1e6+20;

int n;
char S[maxn],T[maxn];

inline void init()
{
	n=read();
	scanf("%s",S+1);
	scanf("%s",T+1);
}

int ans;

inline void doing()
{
	deque<int>q;q.push_back(n+1);
	for(int i=n,j=n+1,del=0;i;i--)
	{
		int tmp=j;
		while(j && (j>i || S[j]!=T[i]))j--;
		if(!j)puts("-1"),exit(0);
		if(j==tmp)
		{
			while(!q.empty() && q.back()-del>=i)q.pop_back();
			q.push_back(i+del); 
		}else
		{
			del++;
			if(i!=j)
			{
				chkmax(ans,SZ(q));
				q.push_front(j+del);
			}
		}
	}
	printf("%d\n",ans);
}

int main()
{
	init();
	doing();
	return 0;
}

