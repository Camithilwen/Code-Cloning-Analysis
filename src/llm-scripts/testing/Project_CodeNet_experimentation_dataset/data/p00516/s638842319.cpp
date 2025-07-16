#include<stdio.h>
#include<algorithm>
using namespace std;
int c[100000];
int d[100000];
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++){
		scanf("%d",c+i);
	}
	for(int i=0;i<b;i++){
		int e;
		scanf("%d",&e);
		for(int j=0;j<a;j++){
			if(e>=c[j]){
				d[j]++;
				break;
			}
		}
	}
	int at=0;
	int v=0;
	for(int i=0;i<a;i++)if(v<d[i]){
		v=d[i];
		at=i;
	}
	printf("%d\n",at+1);
}