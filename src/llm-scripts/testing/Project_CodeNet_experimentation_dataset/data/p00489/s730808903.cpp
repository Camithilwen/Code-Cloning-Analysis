#include<stdio.h>
int main(void)
{
	int i,j,n,n1;
	int a,b,c,d;
	int cnt[100];
	int sum[100];
	
	scanf("%d",&n);
	n1=n*(n-1)/2;
	for (i=0; i<n; i++) {
		sum[i]=0;
		cnt[i]=1;
	}
	for(i=0;i<n1;i++){
		scanf("%d %d %d %d",&a,&b,&c,&d);
		if(c>d){
			sum[a-1]+=3;
		}
		else if(c<d){
			sum[b-1]+=3;
		}
		else{
			sum[a-1]+=1;
			sum[b-1]+=1;
		}
	}
	for (i=0; i<n;i++) {    
		for (j=0;j<n;j++){
			if(sum[i]<sum[j]){
				cnt[i]++;
				
			}
		}
		printf("%d\n",cnt[i]);
	}
	return 0;
}