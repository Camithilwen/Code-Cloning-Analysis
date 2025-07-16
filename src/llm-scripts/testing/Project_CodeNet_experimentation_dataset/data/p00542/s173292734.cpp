#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
int main()
{
	int i,a[4],b,c,sum;
	for(i=0;i<4;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d %d",&b,&c);
	sort(a,a+4,greater<int>());
	for(i=0;i<3;i++){
		sum+=a[i];
	}
	if(b>c){
		sum+=b;
	}
	else{
		sum+=c;
	}
	printf("%d\n",sum);
	return 0;
}

