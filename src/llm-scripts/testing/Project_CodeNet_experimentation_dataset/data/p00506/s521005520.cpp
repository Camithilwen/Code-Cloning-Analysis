#include<stdio.h>
int main(void)
{
	int n;
	int a[3],b,c;
	int i,j,temp;
	b=1;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	if(n==2){
		if(a[0]<a[1]){
			temp=a[0];
			a[0]=a[1];
			a[1]=temp;
		}
		while(b!=a[1]){
			for(i=0;i<a[1];i++){
				if(a[0]%b==0 && a[1]%b==0){
					printf("%d\n",b);
				}
			b++;
			}
		break;
		}
	}
	else if(n==3){
		for(i=0;i<2;i++){
			for(j=i+1;j<3;j++){
				if(a[i]<a[j]){
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
		while(b!=a[2]){
			for(i=0;i<a[2];i++){
				if(a[0]%b==0 && a[1]%b==0 && a[2]%b==0){
						printf("%d\n",b);
				}
			b++;
			}
		break;
		}
	}
	return 0;
}