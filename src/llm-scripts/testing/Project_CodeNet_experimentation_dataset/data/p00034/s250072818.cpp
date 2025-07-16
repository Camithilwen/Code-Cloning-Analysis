#include <stdio.h>

int main(void){
	int l[10];
	int v1, v2;
	int len, tl;
	float p;
	while(scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
		l, l+1, l+2, l+3, l+4, l+5, l+6, l+7, l+8, l+9, &v1, &v2) != EOF){
		len = 0;
		for(int i=0;i<10; ++i){
			len += l[i];
		}
		p = v1 * len / (float)(v1 + v2);
		if(p == 0.0){ puts("0"); break;}
		tl = 0;
		for(int i=0; i<10; ++i){
			tl += l[i];
			if(tl == p){
				printf("%d\n", i+1);
				break;
			}else if(tl > p){
				printf("%d\n", i+1);
				break;
			}
		}
	}
	return 0;
}