#include<stdio.h>
	int main(){
		int A,B,C;
		
		scanf ("%d",&A);
		scanf ("%d",&B);
		scanf ("%d",&C);
		
		if (A==B && A==C && B==A && B==C && C==A && C==B){
			printf ("No\n");
		}else if (A==B||A==C||B==A||B==C||C==A||C==B){
			printf("Yes\n");
		}else {
			printf ("No\n");
		}
	}
