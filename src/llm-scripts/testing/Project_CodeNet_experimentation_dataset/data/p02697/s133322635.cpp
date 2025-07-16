#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(n&1)for(int i=1;i<=m;i++){
		printf("%d %d\n",i,n-i);
	}
	else{
		int cnt = 0;
		for(int i=1;cnt<m&&i<=n/4;cnt++,i++){
			printf("%d %d\n",i,n/2-i+1);
		}
		int cur = 1;
		for(int i=n/2+1;cnt<m;i++,cnt++){
			printf("%d %d\n",i,n-cur);
			cur++;
		}
	}
}
