#include <stdio.h>
#include <string.h>

void shift(char *str, int len, int n){
	char t[] = "abcdefghijklmnopqrstuvwxyz";
	char c;
	for(int i=0; i<len; ++i){
		c = *(str + i);
		if(c >= 'a' && c <= 'z'){
			str[i] = t[(c-'a'+n)%26];
		}
	}
}

int main(void){
	char input[81];
	char copy[81];
	char *token;
	int len = 0;
	int n = 0;

	while(fgets(input, 80, stdin) != NULL){
		n = -1;
		strcpy(copy, input);

		token = strtok(copy, " .\n");
		while(token != NULL && n == -1){
			len = strlen(token);
			if(len == 4){
				for(int i=0;i<26; ++i){
					shift(token, 4, 1);
					if(strcmp(token, "this")==0 ||
						strcmp(token, "that")==0){
						n = i + 1;
						break;
					}
				}
			}else if(len ==3){
				for(int i=0;i<26; ++i){
					shift(token, 3, 1);
					if(strcmp(token, "the")==0){
						n = i + 1;
						break;
					}
				}
			}
			token = strtok(NULL, " .\n");
		}
		shift(input, strlen(input), n);
		printf(input);
	}
	return 0;
}