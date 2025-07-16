#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N],t[N];
int n,ans,l=1,r,last,q[N];
int main(){
	scanf("%d%s%s",&n,s+1,t+1),last=n;
	for(int i=n;i;){
		while(last&&(i<last||s[last]!=t[i])) --last;
		if(!last)	{puts("-1");return 0;}
		while(l<=r&&q[l]-r+l-1>=i)	++l;
		q[++r]=last;
		if(i!=last) ans=max(ans,r-l+1);
		while(t[i]==s[last]&&i>=last)	--i;
	}
	printf("%d\n",ans);
	return 0;
}
