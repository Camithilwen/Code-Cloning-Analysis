#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,y;
	int i,j,flg=0;
	scanf("%d %d",&n,&y);
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			if(n-(i+j)<0) {
				break;
			}
			if(i+j+n-(i+j)==n&&y==i*10000+j*5000+(n-(i+j))*1000){
				flg=1;
				break;
			}
		}
		if(flg==1) break;
	}
	if(flg==1){
		printf("%d %d %d\n",i,j,n-(i+j));
	}
	else if(flg==0||flg==2){
		printf("-1 -1 -1\n");
	}
	return 0;
}