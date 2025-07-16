#include <stdio.h>
#include <string.h>

int main() {
	int ining;
	int ten[50];
	int base[3];
	char act[8];
	int outCnt = 0;
	
	for(int i=0;i<50;i++){
		ten[i] = 0;
	}
	
	for(int i=0;i<3;i++){
		base[i] = 0;
	}
	
	scanf("%d",&ining);
	
	for(int i=0;i<ining;i++){
		while(outCnt < 3){
			scanf("%s",act);
			if(strcmp(act,"HIT") == 0) {
				ten[i] = ten[i] + base[2];
				base[2] = base[1];
				base[1] = base[0];
				base[0] = 1;
			} else if(strcmp(act,"HOMERUN") == 0) {
				for(int l=0;l<3;l++){
					ten[i] = ten[i] + base[l];
					base[l] = 0;
				}
				ten[i] = ten[i] + 1;
			} else if(strcmp(act,"OUT") == 0) {
				outCnt++;
			}
		}
		outCnt = 0;
		for(int i=0;i<3;i++){
			base[i] = 0;
		}
	}
	
	for(int i=0;i<ining;i++)
		printf("%d\n",ten[i]);
	
	return 0;
}
