#include <stdio.h>

int main() {
	int n;
	scanf("2017/01/%d", &n);
	if(n<10){
		printf("2018/01/0%d", n);
	}
	else{
		printf("2018/01/%d", n);
	}
	
	return 0;
}