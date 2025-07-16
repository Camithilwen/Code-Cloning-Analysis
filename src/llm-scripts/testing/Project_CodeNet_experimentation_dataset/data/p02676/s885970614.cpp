#include <stdio.h>

#include <string.h>

 

int x;

char y[101];

 

int main(){

	scanf("%d",&x);	scanf("%s",&y);

	int len = strlen(y);

	if(len<=x){

		printf("%s\n",y);

		return 0;

	}

	else{

		for(int i=x; i<len; i++){

			y[i]='\0';

		}

		for(int i=x; i<x+3; i++){

			y[i]='.';

		}

		printf("%s\n",y);

		return 0;

	}

}