#include<stdio.h>

int main()
{
	int n,i,j=0,k;
	char str[1008],temp;
	
	scanf("%d",&n);
	temp=getchar();
	for(i=0;i<n;i++){
		for(j=0;;j++){
			str[j] = getchar();
			if(str[j] == '\n'){
				str[j] = '\0';
				break;
			}
		}
		
		for(k=0;k<j;k++){
			if(str[k]=='H' && str[k+1]=='o' && str[k+2]=='s' && str[k+3]=='h' && str[k+4]=='i' && str[k+5]=='n' && str[k+6]=='o')str[k+6]='a';
		}
		printf("%s\n",str);
	}
	
	return 0;
}