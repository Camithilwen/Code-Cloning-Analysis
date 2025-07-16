#include <stdio.h>
int main (){
	int numberS, a, b, c;
	scanf("%d", &numberS);
  a = numberS%10;
  b = numberS/100;
  c = numberS%100/10;
	if(a==7 || b==7 || c==7){
		printf("Yes");
	}
	else{
		printf("No");
	}


}