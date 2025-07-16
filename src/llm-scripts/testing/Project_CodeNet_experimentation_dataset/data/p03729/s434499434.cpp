#include <stdio.h>
#include <string.h>

int main (){
	char a[100];
	char b[100];
	char c[100];
	scanf("%s %s %s", a, b, c);
	
	int A = strlen(a);
	int B = strlen (b);
	
	for (int i = 0; i < 10; i++){
		if ( a[A - 1] == b[0] && b[B - 1]== c[0]){
			puts ("YES");
			break;
		}
		else{
			puts ("NO");
			break;
		}
	}
	
	return 0;
}