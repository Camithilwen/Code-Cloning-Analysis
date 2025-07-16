#include<stdio.h>
#include<string.h>

int main(){
	char s[85];
	int i;
	memset(s,'0',sizeof(s));
	while(fgets(s,83,stdin)){

		while(1){
			for(i=0;i<81;i++){
				switch(s[i]){
				case '.':
				case ' ':
				case '0':
				case '\0':
				case 10:
				case 13:
					continue;
				}
				s[i]='a'+(s[i]-'a'+1)%26;
			}
			if((NULL!=strstr(s,"the")) || (NULL!=strstr(s,"this")) || (NULL!=strstr(s,"that"))){
				printf("%s",s);
				memset(s,'0',sizeof(s));
				break;
			}
		}
	}
	return 0;
}