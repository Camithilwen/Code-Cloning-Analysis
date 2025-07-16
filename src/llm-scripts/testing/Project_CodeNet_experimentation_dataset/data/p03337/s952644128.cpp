#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int i,a,b,m[3];
	scanf("%d %d",&a,&b);
	for(i=0;i<3;i++){
		m[0]=a+b;
		m[1]=a-b;
		m[2]=a*b;
	}
	sort(m,m+3);
	printf("%d\n",m[2]);
	return 0;
}
	