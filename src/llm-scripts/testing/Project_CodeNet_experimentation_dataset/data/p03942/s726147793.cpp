#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int n,ans;
char a[1000005],t[1000005];
int pre;

queue<int>Q;

int same(){
	for(int i=1;i<=n;i++){
		if(a[i]!=t[i])return 0;
	}return 1;
}

int main(){
	scanf("%d",&n);
	scanf("%s",a+1);
	for(int i=1;i<=n;i++)a[i]-='a'-1;
	scanf("%s",t+1);
	for(int i=1;i<=n;i++)t[i]-='a'-1;
	if(same()){
		printf("0\n");
		return 0;
	}int i=n,pre=0;
	for(int j=n;j;j--){
		i=min(i,j);
		while(i&&a[i]!=t[j])i--;
		if(i==0){
			printf("-1");
			return 0;
		}if(i==pre)continue;
		pre=i;
		while((!Q.empty())&&j<=Q.front()-Q.size())Q.pop();
		Q.push(pre);
		ans=max(ans,(int)Q.size());
	}printf("%d\n",ans);
	return 0;
}