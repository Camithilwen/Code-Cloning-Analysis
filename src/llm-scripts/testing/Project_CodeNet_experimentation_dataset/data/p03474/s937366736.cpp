#include<stdio.h>
#include<string.h>

int main(){
    int a,b,total=0;
	scanf("%d %d",&a,&b);
	
    char s[a+b+2];
    scanf("%s", &s);
    
    for(int i=0; i<a+b+1 ;i++){
        if(i!=a){
            if(s[i]>=48 && s[i]<=57){
                total++;
            } 
        } 
		else {
            if(s[i] == '-'){
                total++;
            }
        }
    }
    
    if (total==a+b+1){
    	printf("Yes");
	}
	else {
		printf("No");
	}
    
    return 0;
}