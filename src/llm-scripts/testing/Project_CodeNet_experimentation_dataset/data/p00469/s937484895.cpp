#include <stdio.h>
#include <stdlib.h>

int n,k,card[10],count;
int check[10001];

// used[i]==1ÈçÎ iÍgÁÄ¢é
// used[i]==1ÈçÎ card[i]ÍgÁÄ¢é

void func(int a[],int now)
{
	int i,j,temp,keta=0,flg;
	
	if(now == k){
		char str[9];
		for(i=0;i<k;i++){
			temp=sprintf(str+keta,"%d",a[i]);
			keta+=temp;
		}
		temp=atoi(str);
		check[count]=temp;
		count++;
	}
	
	else {
		int used[10] = { 0 };
		
		for(i=0; i<now; i++){
			for(j=0;j<n;j++){
				if(a[i]==card[j] && used[j]==0){
					used[j]=1;
					break;
				}
			}
		}
		
		for(i=0;i<n;i++){
			if(used[i] == 0){
				a[now] = card[i];
				func(a,now+1);
			}
		}
	}
}

int main(void)
{
	int i,j,array[5];
	while(scanf("%d",&n),n){
		scanf("%d",&k);
		for(i=0;i<n;i++){
			scanf("%d", &card[i]);
		}
		
		func(array,0);
		for(i=0;i<count;i++){
			for(j=0;j<count;j++){
				if(check[i]==check[j] && i!=j && check[i]!=0){
					check[j]=0;
				}
			}
		}
		
		count=0;
		for(i=0;i<10000;i++){
			if(check[i]!=0){
				count++;
			}
		}
		printf("%d\n",count);
		
		for(i=0;i<10001;i++){
			check[i]=0;
		}
		count=0;
		for(i=0;i<10;i++){
			card[i]=0;
		}
		
	}
	return 0;
}