#include<stdio.h>
int main(void)
{
	int n,m,i,j,q,a[5000],b[5000],c[5000],d[5000],s[500],z[500];
	scanf("%d",&n);
	m=n*(n-1)/2;
	for(i=1;i<=m;i++){
		scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
	}
	for(j=1;j<=n;j++){
		s[j]=0;
		z[j]=1;
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(j==a[i]){
				if(c[i]>d[i]){
					s[j]+=3;
				}
				else if(c[i]==d[i]){
					s[j]+=1;
				}
			}
			if(j==b[i]){
				if(c[i]<d[i]){
					s[j]+=3;
				}
				else if(c[i]==d[i]){
					s[j]+=1;
				}
			}
		}
	}
	for(j=1;j<=n;j++){
		for(q=1;q<=n;q++){
			if(s[j]<s[q]){
				z[j]++;
			}
		}
		printf("%d\n",z[j]);
	}
	return 0;
}
			