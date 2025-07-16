#include<stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	
	int ratusan = 0, puluhan = 0, satuan= 0;
	
	ratusan = n / 100;
	puluhan = (n / 10) - (ratusan * 10); //misal n = 271, 271 - 2
	satuan = n % 10;
	
	if(ratusan == 7 || puluhan == 7 || satuan == 7){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}