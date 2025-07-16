#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int a[10],ans=0;
	for(int iii=1;iii<=2;iii++){
		ans=0;
	for(int i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+10);
	ans+=a[7]+a[8]+a[9];
	if(iii==1)printf("%d ",ans);
	else printf("%d\n",ans);

	}
	return 0;
}