#include<stdio.h>
 
int main(){
  char a[100];
  scanf("%[^\n]", a);
	int ctr = 0;
	
  for(int i= 0; a[i] != '\0'; i++){
    if(a[i] == ' '){
		if(a[i - 1] == a[i + 1]){
			ctr++;
		}
    }
  }
  if(ctr == 2){
  	printf("YES\n");
  }
  else{
  	printf("NO\n");
  }
  return 0;
}