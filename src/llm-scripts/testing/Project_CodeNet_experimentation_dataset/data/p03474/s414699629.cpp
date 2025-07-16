#include<stdio.h>
int main (){
	int A;
	int B;
	char str1[100];
	int hasil;
	
	scanf("%d %d", &A,&B);
	char str[(A+B)+1];
	scanf("%s", &str);
	
	for(int i=0;i<A+B+1;i++){
	if(i!=A){
		if(str[i]>='0'&&str[i]<='9'){
			hasil++;
		}
	}else if(str[i]=='-'){
			hasil++;
	}
	}
		
		if(hasil==A+B+1){
			printf("Yes");
		}else{
			printf("No");
		}
	return 0;
}