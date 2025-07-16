#include<stdio.h>

int main(){
	char a[150];
	int x=1;
	scanf("%[^\n]", a);
	for (int i=0 ; a[i]!='\0' ; i++){
		if (a[i]==' '){
			if (a[i-1]==a[i+1]){
				continue;
			} else{
				x=0;
				break;
			}
		}
	}
	printf("%s\n", x==1 ? "YES" : "NO");
	return 0;
}