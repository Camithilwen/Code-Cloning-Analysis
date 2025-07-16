#include <iostream>
#include <algorithm>
using namespace std;
int a[100005],b[100005],ans[100005];
int low[100005];
int main(){
	int n,i,len,fin;
	int x;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=n;i++){
        a[i]=b[n-i+1];
	}

	len=0; low[++len]=a[1]; ans[1]=len;
	for(i=2;i<=n;i++){//遍历a[i]
		if(a[i]>=low[len])
			low[++len]=a[i];
		else
			*lower_bound(low+1,low+1+len,a[i]+1)=a[i];//第一个大于a[i]的数，替换掉
		ans[i]=len;
	}
	/*
	for(i=1,x=0;i<=n;i++){
        printf("%d ",ans[i]);
	}
	*/
	printf("%d\n",ans[n]);
	return 0;
}
