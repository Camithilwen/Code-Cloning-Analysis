#include<stdio.h>
#include<string.h>

int main(){
	char A[11], B[11], C[11];
	scanf("%s  %s  %s", A, B, C);
	
	if (A[strlen(A) - 1] == B [0] && B[strlen(B) - 1]  == C [0]){
		printf ("YES\n");
	}
	else {
		printf ("NO\n");
	}
	
	return 0; 
}