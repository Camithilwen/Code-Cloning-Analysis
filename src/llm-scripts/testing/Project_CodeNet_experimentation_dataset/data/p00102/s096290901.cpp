#include<stdio.h>
int main()
{
	int masu[12][12];
	int n,i,j,w=0,h=0,t=0;
	
	for(;;h=0,w=0,t=0){
		for(i=0;i<11;i++){
			for(j=0;j<11;j++){
				masu[i][j]=0;
			}
		}
		scanf("%d",&n);
		if(n==0)break;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&masu[i][j]);
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				w+=masu[i][j];
				h+=masu[j][i];
			}
			masu[i][j]=w;
			masu[j][i]=h;
			w=0;
			h=0;
		}
		
		for(i=0;i<=n;i++){
			t+=masu[n][i];
		}
		masu[i-1][j]=t;
		for(i=0;i<=n;i++){
			for(j=0;j<=n;j++){
				printf("%5d",masu[i][j]);
			}
			puts("");
		}
	}
	return 0;
}