#include <stdio.h>

int main(){
	char arr[355];
	scanf("%[^\n]", &arr);
	int test = 1;
	for(int i=0;arr[i]!='\0';i++){
		if(arr[i]==' '&&arr[i-1]!=arr[i+1]){
			test=0;
			break;
		}
	}
	if(test==1){
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
	return 0;
}