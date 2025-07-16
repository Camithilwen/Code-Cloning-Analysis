#include <stdio.h>
int main(void)
{
	int n,a[4],t[100],p[100],i,j,k;
	scanf("%d",&n);
	for(i=0;i!=n;++i)
		t[i]=0;
	for(i=0;i!=n*(n-1)/2;i++){
		for(j=0;j!=4;j++)
			scanf("%d",&a[j]);
		if(a[2]<a[3])
			t[a[1]-1]+=3;
		else if(a[2]>a[3])
			t[a[0]-1]+=3;
		else{
			t[a[0]-1]+=1;
			t[a[1]-1]+=1;
		}
	}
	for(i=0;i!=n;++i)
		p[i]=t[i];
	for(i=0;i!=n;++i){
		for(j=i;j!=n;j++){
			if(p[i]<p[j]){
				k=p[i];
				p[i]=p[j];
				p[j]=k;
			}
		}
	}
	for(i=0;i!=n;++i){
		for(j=0;j!=n;++j){
			if(t[i]==p[j]){
				printf("%d\n",j+1);
				break;
			}
		}
	}
}