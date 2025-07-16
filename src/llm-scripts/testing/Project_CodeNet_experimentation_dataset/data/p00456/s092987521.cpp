#include<stdio.h>
#include<algorithm>
using namespace std;
int main(void)
{
	int i,a[10],b[10],s,ss;
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
//		printf("a=%d\n",a[i]);
	}	
	sort(a,a+10);
	
	for(i=0;i<10;i++){
	}

	for(i=0;i<10;i++){
		scanf("%d",&b[i]);
	}	
	sort(b,b+10);
	for(i=0;i<10;i++){
	}
	
	s=a[7]+a[8]+a[9];
	ss=b[7]+b[8]+b[9];
	printf("%d %d\n",s,ss);
	return 0;
}
	