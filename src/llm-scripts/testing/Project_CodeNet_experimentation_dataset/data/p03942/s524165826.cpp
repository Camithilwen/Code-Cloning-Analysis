#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#define RG register
using namespace std;
const int N=1e6+10;
int n,ans;
char st[N],ed[N];
queue<int> pn;
inline int mi(int a,int b){return a<b ? a : b;}
inline int mx(int a,int b){return a>b ? a : b;}
int main()
{
//	freopen("Shik and Copying String.in","r",stdin);
	scanf("%d%s%s",&n,st+1,ed+1);
	if(!strcmp(st+1,ed+1)) return printf("0\n"), 0;
	for(int i=n,j=n;i;i--)
	{
		if(ed[i]==ed[i-1]) continue;
		j=mi(i,j);
		while(ed[i]!=st[j] && j) j--;
		if(!j) return printf("-1\n"), 0;
		while(!pn.empty())
		 if((int)pn.front()-(int)pn.size()>=i) pn.pop();
		 else break;
		pn.push(j);
		if(i!=j) ans=mx(ans,(int)pn.size());
	}
	printf("%d\n",ans+1);
	return 0;
}