#include <stdio.h>
int main (){
	long long int a;
	long long int hasil=0;
	scanf("%lld",&a);
	for (int i=1 ; i<=a ; i++){
	
	if (i%3==0 && i%5==0){
//		puts("Fizzbuzz");
	}
	else if (i%3==0){
//		puts ("Fizz");
	}
	else if (i%5==0){
//		puts("Buzz");
	}
	else{
		
	hasil=(hasil+i);
		
	}	
	
	}
	printf("%lld",hasil);
	return 0;
}