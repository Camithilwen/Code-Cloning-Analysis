#include<stdio.h>
int main(){
	char tanggal[15];
	scanf("%s", &tanggal);
	tanggal[3] = '8';
	printf ("%s", tanggal);
	
	return 0;
}