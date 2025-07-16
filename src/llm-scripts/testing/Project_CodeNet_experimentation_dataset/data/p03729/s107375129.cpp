#include <stdio.h>
#include <string.h>
int main (){
	char a[3][35];
	int length [3];
	for (int i = 0;i<3;i++){
	scanf ("%s", a[i]);
	length[i]=strlen(a[i]);
	}
	if(a[0][length[0]-1]== a[1][0] &&a[1][length[1]-1]==a[2][0]){
		printf("YES");
	}else{
		printf("NO");
	}
	return 0;
}