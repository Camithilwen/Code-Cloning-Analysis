#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char convNext(char ch) {
	if('a' <= ch && ch <= 'y') return ch+1;
	if(ch=='z')return 'a';
	return ch;
}
int main() {
	char str[90];
	while(true) {
		if(!fgets(str, 90, stdin))break;
		for(int i = 0; i < 26; i++) {
			if(strstr(str,"this") || strstr(str,"that") || strstr(str,"the"))break;
			for(int j = 0; str[j]; j++) {
				str[j]=convNext(str[j]);
			}
		}
		fputs(str, stdout);
	}
	return 0;
}