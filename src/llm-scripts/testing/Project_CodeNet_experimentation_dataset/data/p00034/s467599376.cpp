#include <cstdio>
int main(){
	float l[10], v, w;
	while(~scanf("%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f",l,l+1,l+2,l+3,l+4,l+5,l+6,l+7,l+8,l+9,&v,&w)){
		int a = 0, r, d=0, i=0;
		for(;i<10;i++)d+=l[i];

		for(i=0;i<10;i++){
			a += l[i];
			if(d*v/(v+w) <= a){r = i + 1;break;}
		}
		printf("%d\n", r);
	}
}