#include <stdio.h>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	char code[n + k + 1];
	scanf("%s", code);
	int temp = 0;
	for (int i = 0; i < n + k + 1; i++){
		if (i != n){
			if (code[i] >= '0' && code[i] <= '9'){
				temp++;	
			}
		}
		else if (code[i] == '-'){
			temp++;
		}
	}
	if (temp == n + k + 1){
		puts("Yes");
	}
	else{
		puts("No");
	}
	return 0;
}