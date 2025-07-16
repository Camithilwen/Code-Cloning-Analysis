#include<stdio.h>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,x[100][3],y[100],a,b,c,d,flg;
	int i,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		x[i][0]=0; x[i][1]=0; x[i][2]=0; y[i]=i;
	}
	for(i=0;i<n*(n-1)/2;i++){
		scanf("%d %d %d %d",&a,&b,&c,&d);
		a--; b--;
		if(c>d){
			x[a][0]++; x[b][1]++;
		}
		else if(c<d){
			x[a][1]++; x[b][0]++;
		}
		else{
			x[a][2]++; x[b][2]++;
		}

	}
	for(i=0;i<n;i++){
		x[i][0]=x[i][0]*3+x[i][2];
	}
	for(i=0;i<n-1;i++){
		for(k=i+1;k<n;k++){
			if(x[i][0]<x[k][0]){
				swap(x[i][0],x[k][0]); swap(y[i],y[k]);
			}
		}
	}
	k=1;
	for(i=0;i<n;i++){
		x[i][1]=k; k++;
		if(x[i][0]==x[i-1][0]) x[i][1]=x[i-1][1];
	}
	for(i=0;i<n-1;i++){
		for(k=i+1;k<n;k++){
			if(y[i]>y[k]){
				swap(y[i],y[k]); swap(x[i][1],x[k][1]); swap(x[i][0],x[k][0]);
			}
		}
	}
	for(i=0;i<n;i++) printf("%d\n",x[i][1]);
	return 0;
}