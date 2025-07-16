#include<stdio.h>
int main()
{
	int i,a,w1=0,w2=0,w3=0,k1=0,k2=0,k3=0;
	for(i=0;i<10;i++){
		scanf("%d",&a);
		if(w3<a){
			w3=a;
			if(w2<a){
				w3=w2;
				w2=a;
				if(w1<a){
					w2=w1;
					w1=a;
				}
			}
		}
	}
	for(i=0;i<10;i++){
		scanf("%d",&a);
		if(k3<a){
			k3=a;
			if(k2<a){
				k3=k2;
				k2=a;
				if(k1<a){
					k2=k1;
					k1=a;
				}
			}
		}
	}
	printf("%d %d\n",w1+w2+w3,k1+k2+k3);
	return 0;
}