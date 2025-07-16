#include <stdio.h>
int main(){
	
	int n,k,bank = 1;
	
	scanf("%d" , &n);
	scanf("%d" , &k);
	
	for(int i = 0 ; i < n ; i++){
		if(bank * 2 > bank + k){
			bank += k;
		}
		else{
			bank *= 2;
		}		
	}
	printf("%d" , bank);
	
	return 0;
}