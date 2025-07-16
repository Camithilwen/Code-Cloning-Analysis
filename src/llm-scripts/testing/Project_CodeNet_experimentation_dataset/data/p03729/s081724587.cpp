#include <stdio.h>
#include <string.h>

int main(){
	char A[11], B[11], C[11];
	scanf("%s %s %s", A, B, C);
	
	int lenA=0, lenB=0, lenC=0;
	lenA = strlen(A);
	lenB = strlen(B);
	lenC = strlen(C);
	
	if(A[lenA-1] == B[0] && B[lenB-1] == C[0] ){
		printf("YES");
	} else {
		printf("NO");
	}

	return 0;
}