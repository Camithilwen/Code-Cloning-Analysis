#include <stdio.h>
#include <string.h>

int main(){
 	
	char strA[100], strB[100], strC[100];
 	scanf("%s %s %s",&strA, &strB, &strC);
 	
	int lenA=strlen(strA);
 	int lenB=strlen(strB);
 	
 	if (strA[lenA-1] == strB[0] && strB[lenB-1] == strC[0]){
 		printf("YES");
	 }
	 
	 else{
	 	printf("NO");
	 }
 	
	return 0;	
	
	}