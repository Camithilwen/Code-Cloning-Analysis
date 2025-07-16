#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define N 1000005
queue<int> q;
char a[N],b[N];
int main()
{
	int n,i,j,ans=0;
	scanf("%d%s%s",&n,a+1,b+1);
	if(strcmp(a+1,b+1)==0){printf("0");return 0;}
	i=j=n;
	while(j){
		while(j&&b[j]==b[j-1])j--;
		while(i&&(i>j||a[i]!=b[j]))i--;
		if(i==0){printf("-1");return 0;}
		while(!q.empty()&&q.front()-(int)q.size()>=j)q.pop();
		if(i!=j)q.push(i);
		ans=max(ans,(int)q.size()+1);
		j--;
	}
	printf("%d",ans);
}